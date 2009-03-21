/***************************************************************************
    netoverride.c - Network function overrides for NWN
    Copyright (C) 2007 Doug Swarin (zac@intertex.net)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdarg.h>

#include <fcntl.h>
#include <time.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>

#define __USE_GNU
#include <dlfcn.h>

#include "openoverride.h"

#undef OPENOVERRIDE_DEBUG


static fd_set oo_fds;
static int (*oo_open)(const char *, int, ...) = NULL;
static FILE *(*oo_fopen)(const char *, const char *) = NULL;
static int (*oo_close)(int) = NULL;
static int (*oo_fclose)(FILE *) = NULL;

static struct openoverride_file_s *oo_module = NULL;


static void oo_log (const char *fmt, ...) __attribute__(( format (printf, 1, 2) ));


static void oo_log (const char *fmt, ...) {
  size_t len;
  time_t t;
  struct tm tm;
  va_list vap;

  static int fd = -1;
  static char buf[1024];

  if (fd < 0)
    fd = oo_open("logs.0/openoverride.txt", O_WRONLY|O_APPEND|O_CREAT, 0644);

  if (fd < 0)
    return;

  t = time(NULL);
  localtime_r(&t, &tm);

  strftime(buf, sizeof(buf), "[%Y-%m-%d %H:%M:%S] ", &tm);

  len = strlen(buf);
  va_start(vap, fmt);
  vsnprintf(buf + len, (sizeof(buf) - len), fmt, vap);
  va_end(vap);

  len = strlen(buf);
  buf[len] = '\n';

  write(fd, buf, len + 1);
}


static void oo_init (const char *source) {
  oo_open   = dlsym(RTLD_NEXT, "open");
  oo_fopen  = dlsym(RTLD_NEXT, "fopen");
  oo_close  = dlsym(RTLD_NEXT, "close");
  oo_fclose = dlsym(RTLD_NEXT, "fclose");

  FD_ZERO(&oo_fds);

  oo_log("binding functions from %s:", source);
  oo_log("  open found at %p",  oo_open);
  oo_log("  close found at %p", oo_close);
  oo_log("  fopen found at %p", oo_fopen);
  oo_log("  fclose found at %p", oo_fclose);
}


static inline void oo_attach (struct openoverride_file_s *f, const char *path) {
  if (f->fd < 0) {
    if ((f->fd = oo_open(path, O_RDONLY)) >= 0) {
      f->file = fdopen(f->fd, "rb");

      oo_log("opened '%s' as fd %d file %p", path, f->fd, f->file);
      FD_SET(f->fd, &oo_fds);
    }

    if (f->module > 0)
      oo_module = f;
  } else {
    fseek(f->file, 0, SEEK_SET);
    lseek(f->fd,   0, SEEK_SET);
  }
}


int open (const char *path, int flags, ...) {
  struct openoverride_file_s *f;

  if (oo_open == NULL)
    oo_init("open");

#ifdef OPENOVERRIDE_DEBUG
  oo_log("request for file '%s' with flags %d", path, flags);
#endif

  if (flags != O_RDONLY || (f = oo_lookup(path, strlen(path))) == NULL)
    return oo_open(path, flags, 0666);

  oo_attach(f, path);
  return f->fd;
}


FILE *fopen (const char *path, const char *mode) {
  struct openoverride_file_s *f;

  if (oo_fopen == NULL)
    oo_init("fopen");

#ifdef OPENOVERRIDE_DEBUG
  oo_log("request for file '%s' with mode '%s'", path, mode);
#endif

  /* The 'module' parameter in the openoverride structure can have 3 values:
   *   -1 - do not perform module handling
   *    0 - write to /dev/null; read from module
   *    1 - this is the module
   */
  if ((f = oo_lookup(path, strlen(path))) != NULL && f->module == 0) {
    if (mode[0] == 'w' && mode[1] == 'b' && mode[2] == 0)
      return oo_fopen("/dev/null", "wb");

    f = oo_module;
  }

  if (mode[0] != 'r' || mode[1] != 'b' || mode[2] != 0 || f == NULL)
    return oo_fopen(path, mode);

  oo_attach(f, path);
  return f->file;
}


int close (int fd) {
  if (oo_close == NULL)
    oo_init("close");

  if (FD_ISSET(fd, &oo_fds)) {
#ifdef OPENOVERRIDE_DEBUG
    oo_log("not closing file descriptor %d", fd);
#endif
    return 0;
  }

#ifdef OPENOVERRIDE_DEBUG
  oo_log("closing file descriptor %d", fd);
#endif

  return oo_close(fd);
}


int fclose (FILE *fp) {
  if (oo_fclose == NULL)
    oo_init("fclose");

  if (FD_ISSET(fileno(fp), &oo_fds)) {
#ifdef OPENOVERRIDE_DEBUG
    oo_log("not closing file stream %p", fp);
#endif
    return 0;
  }

#ifdef OPENOVERRIDE_DEBUG
  oo_log("closing file stream %p", fp);
#endif

  return oo_fclose(fp);
}


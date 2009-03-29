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

#include <netinet/in.h>
#include <arpa/inet.h>

#include <netdb.h>

#define __USE_GNU
#include <dlfcn.h>

#undef OPENOVERRIDE_DEBUG


static int (*bo_bind)(int, const struct sockaddr *, socklen_t) = NULL;


static void bo_log (const char *fmt, ...) __attribute__(( format (printf, 1, 2) ));


static void bo_log (const char *fmt, ...) {
  size_t len;
  time_t t;
  struct tm tm;
  va_list vap;

  static int fd = -1;
  static char buf[1024];

  if (fd < 0)
    fd = open("logs.0/bindoverride.txt", O_WRONLY|O_APPEND|O_CREAT, 0644);

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


static void bo_init (const char *source) {
  bo_bind  = dlsym(RTLD_NEXT, "bind");

  bo_log("binding functions from %s:", source);
  bo_log("  bind found at %p",  bo_bind);
}


int bind (int fd, const struct sockaddr *addr, socklen_t addrlen) {
  struct sockaddr_in bin;

  if (bo_bind == NULL)
    bo_init("open");

  memcpy(&bin, addr, addrlen);

  if (bin.sin_family == AF_INET && bin.sin_addr.s_addr == 0) {
    const char *addrenv = getenv("NWN_BIND");

    if (addrenv != NULL && strlen(addrenv) > 0 && inet_aton(addrenv, &(bin.sin_addr)) != 0) {
      addr    = (struct sockaddr *)&bin;
      addrlen = sizeof(bin);
    }
  }

  return bo_bind(fd, addr, addrlen);
}


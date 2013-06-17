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
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <netdb.h>

#define __USE_GNU
#include <dlfcn.h>

struct no_nwn_player {
  char *id;

  in_addr_t addr;
  in_port_t port;

  struct no_nwn_player *next;
} *players = NULL;


static void no_log (char *fmt, ...) __attribute__(( format (printf, 1, 2) ));


static void no_log (char *fmt, ...) {
  size_t len;
  time_t t;
  struct tm tm;
  va_list vap;

  static int fd = -1;
  static char buf[1024];

  if (fd < 0)
    fd = open("logs.0/netoverride.txt", O_WRONLY|O_APPEND|O_CREAT, 0644);

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

static char *no_extract_pstring (unsigned char *pstring) {
  static char buf[256];

  /* pstring is guaranteed to be no more than 255 bytes */
  memcpy(buf, (pstring + 1), *pstring);
  buf[*pstring] = 0;

  return buf;
}

static char *no_clear_client (struct sockaddr_in *addr) {
  struct no_nwn_player *p, *next, *prev = NULL;
  static char id[256];

  strcpy(id, "UNKNOWN");

  for (p = players; p != NULL; p = next) {
    next = p->next;

    if (p->addr == addr->sin_addr.s_addr && p->port == addr->sin_port) {
      if (prev == NULL)
        players = next;
      else
        prev->next = next;

      strcpy(id, p->id);

      free(p->id);
      free(p);
    } else
      prev = p;
  }

  return id;
}

static char *no_match_client (char *id, struct sockaddr_in *addr) {
  struct no_nwn_player *p;

  for (p = players; p != NULL; p = p->next) {
    if (p->addr == addr->sin_addr.s_addr && p->port == addr->sin_port) {
      if (strcmp(p->id, id) != 0)
        return NULL;
      return p->id;
    }
  }

  p = malloc(sizeof(struct no_nwn_player));
  p->id   = strdup(id);
  p->addr = addr->sin_addr.s_addr;
  p->port = addr->sin_port;

  p->next = players;
  players = p;

  return p->id;
}


ssize_t recvfrom (int fd, void *buf, size_t len, int flags,
                  struct sockaddr *addr, socklen_t *addrlen) {

  ssize_t ret;
  static ssize_t (*real_recvfrom)(int, void *, size_t, int,
                  struct sockaddr *, socklen_t *) = NULL;
  static char name[256], cdkey[256];

  if (real_recvfrom == NULL)
    real_recvfrom = dlsym(RTLD_NEXT, "recvfrom");

  ret = real_recvfrom(fd, buf, len, flags, addr, addrlen);

  if (ret > 18 && memcmp(buf, "BNCS", 4) == 0) {
    unsigned char *p = buf;
    int ver = *(p + 5);
    struct sockaddr_in *sin = (struct sockaddr_in *)addr;

    if (ver < 20 || *(p + 18) < 1 || *(p + 19 + *(p + 18)) < 1) {
      no_log("rejected invalid login from %s:%d [v%d]",
        inet_ntoa(sin->sin_addr), ntohs(sin->sin_port), ver);

      memcpy(buf, "BNLM\x00\x12\x00\x00\x00\x00\x00", 11);
      return 11;
    }

    strcpy(name, no_extract_pstring(p + 18));
    strcpy(cdkey, no_extract_pstring(p + 19 + *(p + 18)));

    if (no_match_client(cdkey, sin) == NULL) {
      no_log("rejected double lan login from %s:%d by %s (%s) [v%d]",
        inet_ntoa(sin->sin_addr), ntohs(sin->sin_port), name, cdkey, ver);

      memcpy(buf, "BNLM\x00\x12\x00\x00\x00\x00\x00", 11);
      return 11;
    }

    no_log("bound address %s:%d to %s (%s) [v%d]",
      inet_ntoa(sin->sin_addr), ntohs(sin->sin_port), name, cdkey, ver);
  } else if (ret == 4 && memcmp(buf, "BNDM", 4) == 0) {
    struct sockaddr_in *sin = (struct sockaddr_in *)addr;
    char *id = no_clear_client(sin);

    no_log("releasing address %s:%d from %s",
      inet_ntoa(sin->sin_addr), ntohs(sin->sin_port), id);
  }

  return ret;
}

struct hostent *gethostbyname (const char *host) {
  static char *he_aliases[] = { NULL };

  // Gamespy is dead (for NWN), Visant's replacement project also seems dead, 
  // so this could probably just be deleted at some point.
  static char *he_gamespy_addrs[] = { "\xcf\x26\x0b\xae", NULL };

  // Point bioware master address to Skywings master server: 199.193.152.27
  static char ms_addr[] = "\xc7\xc1\x98\x1b";
  static char *he_bioware_addrs[] = { NULL, NULL };
  static struct hostent *(*ghbn)(const char *) = NULL;

  if (he_bioware_addrs[0] == NULL) {
    char *env;
    if ( (env = getenv("NWN_MASTER_ADDR")) && strlen(env) == 4) {
      he_bioware_addrs[0] = strncpy(ms_addr, env, 4);
    }
    else {
      he_bioware_addrs[0] = ms_addr;
    }
  }

  if (ghbn == NULL)
    ghbn = dlsym(RTLD_NEXT, "gethostbyname");

  no_log("resolving %s", host);

  static struct hostent he_gamespy = {
    .h_name = "nwn.master.gamespy.com",
    .h_aliases = he_aliases,
    .h_addrtype = 2,
    .h_length = 4,
    .h_addr_list = he_gamespy_addrs
  };

  static struct hostent he_bioware = {
    .h_name = "nwmaster.bioware.com",
    .h_aliases = he_aliases,
    .h_addrtype = 2,
    .h_length = 4,
    .h_addr_list = he_bioware_addrs
  };

  if (strcmp(host, "nwn.master.gamespy.com") == 0)
    return &he_gamespy;
  if (strcmp(host, "nwmaster.bioware.com") == 0)
    return &he_bioware;

  return ghbn(host);
}

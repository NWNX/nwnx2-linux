
/***************************************************************************
    NWNXFuncs.cpp - Implementation of the CNWNXFuncs class.
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

#include "NWNXFuncs.h"

char *stpcpy(char *dst, const char *src);


void Func_DumpObject(CGameObject *ob, char *value)
{
    int i, j;
    char buf[2048], chbuf[16], prbuf[32], *p;
    unsigned char *dump = (unsigned char *)ob;

    sprintf(buf, "object: %p  tag: %s  type: %d", ob, ob->tag, ob->type);
    p = buf + strlen(buf);

    if (ob->type == 5) {
        sprintf(p, "  creature: %p", ((CNWSCreature *)ob)->cre_stats);
        p = buf + strlen(buf);
    }

    p = stpcpy(p, "\n");

    for (i = 0; i < 16; i++) {
        prbuf[0] = 0;

        for (j = (i * 256); j < ((i + 1) * 256); j++) {
            if (j % 16 == 0) {
                snprintf(chbuf, sizeof(chbuf), "\n0x%04X:  ", j);
                strcat(prbuf, chbuf);
                p = stpcpy(p, prbuf);

                snprintf(prbuf, sizeof(prbuf), "|................|");
            }

            if (j % 8 == 7)
                snprintf(chbuf, sizeof(chbuf), "%02x  ", dump[j]);
            else
                snprintf(chbuf, sizeof(chbuf), "%02x ", dump[j]);

            p = stpcpy(p, chbuf);

            if (dump[j] >= ' ' && dump[j] < 127)
                prbuf[(j % 16) + 1] = dump[j];
        }

        p = stpcpy(p, prbuf);
        p = stpcpy(p, "\n");

        nx_log(NX_LOG_DEBUG, 0, "%s", buf);

        p = buf;
    }
}


/* vim: set sw=4: */

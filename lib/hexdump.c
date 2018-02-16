/*
 *  NWNeXalt - hexdump.c
 *  - dump an area of memory to the log file, as ascii formatted text.
 *
 *  parameters -
 *	void*	the location of memory to dump
 *	int		the number of bytes to dump
 *
 *	returns -
 *	char*	a formatted string that can be used to send to the log file
 *			on error [the required dump length would overflow the buffer],
 *			an error string is returned
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 *  $HeadURL$
 *
 */

#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "hexdump.h"


char *hexdump(void *datap, int osize)
{
	static	char	outbuf[BUFSIZ];
			char	bytebuf[8], asciibuf[22];
			int		i, width;
			u_char *dump = (unsigned char *)datap;

	if (osize >= BUFSIZ / 5) {	// every byte dumped takes 5 to display
		sprintf(outbuf, "hexdump: the required memory area (%d) exceeds the buffer space available (%d)",
			osize, BUFSIZ / 5);
		return outbuf;
	}

	outbuf[0] = 0;
	i = 0;
	while (i < osize) {
		if (i % 16 == 0) {
			if (i > 0)
				strcat(outbuf, asciibuf);
			sprintf(bytebuf, "0x%04x:  ", i);
			strcat(outbuf, bytebuf);
			strcpy(asciibuf, "|................|\n");
		}
		sprintf(bytebuf, "%02x ", *dump);
		strcat(outbuf, bytebuf);
		if (i % 8 == 7)
			strcat(outbuf, " ");
		if (*dump >= ' ' && *dump < 127)
			asciibuf[(i % 16) + 1] = *dump;
		++i, ++dump;
	}

	// extend unused area to align asciibuf
	while (i % 16) {
		if (i % 8 == 7)
			strcat(outbuf, " ");
		strcat(outbuf, "   ");
		asciibuf[(i % 16) + 1] = ' ';
		++i;
	}

	strcat(outbuf, asciibuf);

	return outbuf;
}

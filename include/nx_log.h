/*
 *  NWNeXalt - Empty File
 *  (c) 2007 Doug Swarin (zac@intertex.net)
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

#ifndef _NX_LOG_H_
#define _NX_LOG_H_

#define NX_LOG_DEBUG4           0xFC
#define NX_LOG_DEBUG3           0xFD
#define NX_LOG_DEBUG2           0xFE
#define NX_LOG_DEBUG1           0xFF
#define NX_LOG_DEBUG            0x00
#define NX_LOG_INFO             0x01
#define NX_LOG_NOTICE           0x02
#define NX_LOG_WARNING          0x03
#define NX_LOG_ERROR            0x04
#define NX_LOG_CRITICAL         0x05


#ifndef NX_LOG_FACILITY
#define NX_LOG_FACILITY         0
#endif


#define nx_log(LEVEL, TAGS, ...) nx__log((NX_LOG_FACILITY|LEVEL), TAGS, __VA_ARGS__)
#define nx_log_error(...) nx__log_error((NX_LOG_FACILITY|NX_LOG_ERROR), __FILE__, __LINE__, __func__, __VA_ARGS__)

#define nx_log_init(NAME, FAC) do { nx__log_facility = nx__log_init(NAME, FAC); } while (0)

#ifdef __cplusplus
extern "C" {
#endif

void nx__log(uint32_t, uint16_t, const char *, ...);
void nx__log_error(uint32_t, const char *, int, const char *, const char *, ...);

uint32_t nx__log_init(const char *, int, ...);

#ifdef __cplusplus
}
#endif

#endif /* _NX_LOG_H_ */

/* vim: set sw=4: */

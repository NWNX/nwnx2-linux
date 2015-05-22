/***************************************************************************
    odmbc plugin for NWNX - hooks interface
    copyright (c) 2006 dumbo (dumbo@nm.ru)

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

#ifndef _HookSCORCO_h_
#define _HookSCORCO_h_

typedef unsigned long dword;
typedef unsigned short int word;
typedef unsigned char byte;

int HookFunctions();
void d_enable_write(unsigned long location);


#endif

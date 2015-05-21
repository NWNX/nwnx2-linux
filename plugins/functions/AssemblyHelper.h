/***************************************************************************
    NWNX  - Assembly Helper header
    (c) 2007 virusman (virusman@virusman.ru)

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

#ifndef ASSEMBLYHELPER_H_
#define ASSEMBLYHELPER_H_

#define SEARCH_START_ADDRESS 0x08048000
#define SEARCH_END_ADDRESS   0x08300000

using namespace std;

struct sigbyte {
    char c;
    unsigned char skip;
};

class AssemblyHelper
{
public:
    unsigned long FindFunctionBySignature(const char *pattern);
};


#endif

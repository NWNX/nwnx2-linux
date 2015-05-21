/***************************************************************************
    NWNX  - Assembly Helper implementation
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

#include "AssemblyHelper.h"
#include <string>
/*
Example string:
//55 89 E5 53 83 EC 10 8B 5D 08 8B 43 0C 53 **
*/

unsigned long AssemblyHelper::FindFunctionBySignature(const char *pattern)
{
    std::string str_pattern = pattern;

    //Strip whitespace
    string::iterator i;
    for (i = str_pattern.begin(); i < str_pattern.end(); i++) {
        if (*i == ' ' || *i == '\t') {
            //whitespace
            str_pattern.erase(i);
            i--;
        }
    }
    char *curr_pattern = new char[str_pattern.length()];
    unsigned int curr_pattern_len = str_pattern.copy(curr_pattern, str_pattern.length());
    sigbyte *list_pattern = new sigbyte[str_pattern.length() / 2];
    unsigned int list_position = 0;
    unsigned int skip = 0;
    char buf[3];
    //Parse the signature string and build a structure
    for (unsigned int i = 0; i < curr_pattern_len; i += 2) {
        //printf("%c%c", curr_pattern[i], curr_pattern[i+1]);
        if (strncmp(curr_pattern + i, "**", 2) == 0) {
            //printf("\n");
            skip++;
        } else if (curr_pattern[i] == '+') {
            strncpy(buf, curr_pattern + i + 1, 2);
            skip += strtol(buf, NULL, 10);
            i++;
        } else {
            strncpy(buf, curr_pattern + i, 2);
            list_pattern[list_position].c = strtol(buf, NULL, 16);
            if (skip > 0) {
                list_pattern[list_position].skip = skip;
                skip = 0;
            } else
                list_pattern[list_position].skip = 0;
            //printf("[%d] - %x, skipped %d\n", list_position, list_pattern[list_position].c, list_pattern[list_position].skip);
            list_position++;
        }
    }
    delete[] curr_pattern;
    unsigned int list_length = list_position;

    //Find the function using the structure
    char *ptr = (char *) SEARCH_START_ADDRESS;
    while (ptr < (char *) SEARCH_END_ADDRESS) {
        bool match = 1;
        unsigned int offset = 0;
        for (unsigned int i = 0; i < list_length; i++) {
            offset += list_pattern[i].skip;
            if (ptr[offset] != list_pattern[i].c) {
                match = 0;
                break;
            }
            offset++;
        }
        if (match) {
            delete[] list_pattern;
            return (unsigned long) ptr;
        }
        ptr++;
    }
    delete[] list_pattern;
    return 0;
}

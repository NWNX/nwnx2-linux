/***************************************************************************
    gline.cpp - Configuration file parser (.ini)
    Copyright (C) 2003 John Klar (paladin at projectplasma dot com)

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

 ***************************************************************************/

#include <map>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "gline.h"

int
gline::parse(const char *fname)
{

    int j, pos;
    string sect, line, key, value;
    ifstream in(fname);

    while (getline(in, line)) {

        // strip inline comments
        if ((j = line.find('#')) != line.npos)
            line.erase(j);

        // strip trailing whitespace
        for (j = line.length() - 1; j >= 0 && isspace(line[j]); --j)
            /* seeking */;
        line.erase(j + 1);

        if (line.size() > 0) {
            // should probably trim leading spacess
            switch (line[0]) {
                case ';':
                case '#':
                case ' ':
                case '\t':
                    break;

                case '[':
                    // extractSection(line,sect);
                    if ((pos = line.find_last_of(']')) != line.npos) {
                        StringMap smap;

                        sect = line.substr(1, pos - 1);
                        config[sect] = smap;
                    }
                    break;

                default:
                    // extractPair
                    if ((pos = line.find('=')) != line.npos) {
                        key = line.substr(0, pos);
                        value = line.substr(pos + 1);
                        delete_spaces(key);
                        delete_spaces(value);
                        config[sect][key] = value;
                    }

            }
        }

    }

    return 0;
}

int
gline::exists(const char *section, const char *key)
{
    if (section == NULL)
        return 0;
    if (config.find(section) != config.end()) {
        if (key != NULL) {
            if (config[section].find(key) != config[section].end())
                return 1;
            else
                return 0;
        }
        return 1;
    }
    return 0;
}

StringMap &
gline::operator[](const char *section)
{
    return config[section];
}

int
gline::open(const char *fname)
{
    return parse(fname);
}

void gline::delete_spaces(string &str)
{
    bool inv_commas = 0;
    string::iterator i;
    for (i = str.begin(); i < str.end(); i++) {
        if ((*i == ' ' || *i == '\t') && !inv_commas) {
            //whitespace
            str.erase(i);
            i--;
        } else if ((*i == '#' || *i == ';') && !inv_commas) {
            //comments
            str.erase(i, str.end());
            i = str.end() - 1;
        } else if (*i == '"') {
            //inverted commas
            str.erase(i);
            i--;
            inv_commas = !inv_commas;
        }
    }
}

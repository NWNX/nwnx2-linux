/***************************************************************************

    gline.h - interface for gline class
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

#ifndef GLINE_H_
#define GLINE_H_

#include <map>
#include <string>
#include <iostream>
#include <fstream>

typedef std::map<std::string, std::string, std::less<std::string> > StringMap;
typedef std::map<std::string, StringMap, std::less<std::string> > MetaStringMap;

class gline
{
private:
    // string section;

protected:
    MetaStringMap config;

    int parse(const char *fname);

public:
    gline() {};
    ~gline() {};

    // parse contents of file
    int open(const char *fname);

    // does section or section+key Exist
    int exists(const char *section, const char *key = NULL);

    StringMap &operator[](const char *key);

    // StringMap &operator[](string key);
private:
    void delete_spaces(std::string &str);
};

#endif

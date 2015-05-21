/***************************************************************************
    plugin-java - Defines the entry point for the DLL application.
    (c) 2009 Bernhard Stoeckner (elven@swordcoast.net)

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

#include "NWNXJVM.h"

CNWNXJVM jvm;
PLUGINLINK *pluginLink = 0;

PLUGININFO pluginInfo = {
    sizeof(PLUGININFO),
    "NWNXJVM",
    PLUGIN_MAKE_VERSION(0, 0, 0, 1),
    "",
    "elven",
    "elven@swordcoast.net",
    "(c) 2009-current elven",
    "",
    0		//not transient
};


extern "C" PLUGININFO* GetPluginInfo(DWORD nwnxVersion)
{
    return &pluginInfo;
}

extern "C" int InitPlugin(PLUGINLINK *link)
{
    pluginLink = link;
    return 0;
}


extern "C"
CNWNXBase* GetClassObject()
{
    return &jvm;
}

//-----------------------------------------------------------------------------
//
// @doc
//
// @module  NwnDefiles.cpp - General helper routines |
//
// This module contains the general NWN helper routines.
//
// Copyright (c) 2002-2003 - Edward T. Smith
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Neither the name of Edward T. Smith nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
// TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// @end
//
// $History: Cnf.cpp $
//
//-----------------------------------------------------------------------------

#include "NwnDefines.h"
#include <string.h>

//-----------------------------------------------------------------------------
//
// @func Return the extension for the given type
//
// @parm NwnResType | nResType | Type of the resource
//
// @rdesc Pointer to the extension or NULL if unknown.
//
//-----------------------------------------------------------------------------

const char *NwnGetResTypeExtension(NwnResType nType)
{
    switch (nType) {
        case NwnResType_RES: return "res";
        case NwnResType_BMP: return "bmp";
        case NwnResType_MVE: return "mve";
        case NwnResType_TGA: return "tga";
        case NwnResType_WAV: return "wav";
        case NwnResType_PLT: return "plt";
        case NwnResType_INI: return "ini";
        case NwnResType_BMU: return "bmu";
        case NwnResType_MPG: return "mpg";
        case NwnResType_TXT: return "txt";
        case NwnResType_PLH: return "plh";
        case NwnResType_TEX: return "tex";
        case NwnResType_MDL: return "mdl";
        case NwnResType_THG: return "thg";
        case NwnResType_FNT: return "fnt";
        case NwnResType_LUA: return "lua";
        case NwnResType_SLT: return "slt";
        case NwnResType_NSS: return "nss";
        case NwnResType_NCS: return "ncs";
        case NwnResType_MOD: return "mod";
        case NwnResType_ARE: return "are";
        case NwnResType_SET: return "set";
        case NwnResType_IFO: return "ifo";
        case NwnResType_BIC: return "bic";
        case NwnResType_WOK: return "wok";
        case NwnResType_2DA: return "2da";
        case NwnResType_TLK: return "tlk";
        case NwnResType_TXI: return "txi";
        case NwnResType_GIT: return "git";
        case NwnResType_BTI: return "bti";
        case NwnResType_UTI: return "uti";
        case NwnResType_BTC: return "btc";
        case NwnResType_UTC: return "utc";
        case NwnResType_DLG: return "dlg";
        case NwnResType_ITP: return "itp";
        case NwnResType_BTT: return "btt";
        case NwnResType_UTT: return "utt";
        case NwnResType_DDS: return "dds";
        case NwnResType_UTS: return "uts";
        case NwnResType_LTR: return "ltr";
        case NwnResType_GFF: return "gff";
        case NwnResType_FAC: return "fac";
        case NwnResType_BTE: return "bte";
        case NwnResType_UTE: return "ute";
        case NwnResType_BTD: return "btd";
        case NwnResType_UTD: return "utd";
        case NwnResType_BTP: return "btp";
        case NwnResType_UTP: return "utp";
        case NwnResType_DTF: return "dtf";
        case NwnResType_GIC: return "gic";
        case NwnResType_GUI: return "gui";
        case NwnResType_CSS: return "css";
        case NwnResType_CCS: return "ccs";
        case NwnResType_BTM: return "btm";
        case NwnResType_UTM: return "utm";
        case NwnResType_DWK: return "dwk";
        case NwnResType_PWK: return "pwk";
        case NwnResType_BTG: return "btg";
        case NwnResType_UTG: return "utg";
        case NwnResType_JRL: return "jrl";
        case NwnResType_SAV: return "sav";
        case NwnResType_UTW: return "utw";
        case NwnResType_4PC: return "4pc";
        case NwnResType_SSF: return "ssf";
        case NwnResType_HAK: return "hak";
        case NwnResType_NWM: return "nwm";
        case NwnResType_BIK: return "bik";
        case NwnResType_NDB: return "ndb";
        case NwnResType_ERF: return "erf";
        case NwnResType_BIF: return "bif";
        case NwnResType_KEY: return "key";
        case NwnResType_PTM: return "ptm";
        case NwnResType_PTT: return "ptt";
        default: return NULL;
    }
}

//-----------------------------------------------------------------------------
//
// @func Return the res type based on the extension
//
// @parm const char * | pszExtension | File extension
//
// @rdesc Resource type or NwnResType_Unknown if not known.
//
//-----------------------------------------------------------------------------

NwnResType NwnGetResTypeFromExtension(const char *pszExtension)
{
    if (*pszExtension == '.')
        pszExtension++;
    if (strcasecmp(pszExtension, "res") == 0)
        return NwnResType_RES;
    if (strcasecmp(pszExtension, "bmp") == 0)
        return NwnResType_BMP;
    if (strcasecmp(pszExtension, "mve") == 0)
        return NwnResType_MVE;
    if (strcasecmp(pszExtension, "tga") == 0)
        return NwnResType_TGA;
    if (strcasecmp(pszExtension, "wav") == 0)
        return NwnResType_WAV;
    if (strcasecmp(pszExtension, "plt") == 0)
        return NwnResType_PLT;
    if (strcasecmp(pszExtension, "ini") == 0)
        return NwnResType_INI;
    if (strcasecmp(pszExtension, "bmu") == 0)
        return NwnResType_BMU;
    if (strcasecmp(pszExtension, "mpg") == 0)
        return NwnResType_MPG;
    if (strcasecmp(pszExtension, "txt") == 0)
        return NwnResType_TXT;
    if (strcasecmp(pszExtension, "plh") == 0)
        return NwnResType_PLH;
    if (strcasecmp(pszExtension, "tex") == 0)
        return NwnResType_TEX;
    if (strcasecmp(pszExtension, "mdl") == 0)
        return NwnResType_MDL;
    if (strcasecmp(pszExtension, "thg") == 0)
        return NwnResType_THG;
    if (strcasecmp(pszExtension, "fnt") == 0)
        return NwnResType_FNT;
    if (strcasecmp(pszExtension, "lua") == 0)
        return NwnResType_LUA;
    if (strcasecmp(pszExtension, "slt") == 0)
        return NwnResType_SLT;
    if (strcasecmp(pszExtension, "nss") == 0)
        return NwnResType_NSS;
    if (strcasecmp(pszExtension, "ncs") == 0)
        return NwnResType_NCS;
    if (strcasecmp(pszExtension, "mod") == 0)
        return NwnResType_MOD;
    if (strcasecmp(pszExtension, "are") == 0)
        return NwnResType_ARE;
    if (strcasecmp(pszExtension, "set") == 0)
        return NwnResType_SET;
    if (strcasecmp(pszExtension, "ifo") == 0)
        return NwnResType_IFO;
    if (strcasecmp(pszExtension, "bic") == 0)
        return NwnResType_BIC;
    if (strcasecmp(pszExtension, "wok") == 0)
        return NwnResType_WOK;
    if (strcasecmp(pszExtension, "2da") == 0)
        return NwnResType_2DA;
    if (strcasecmp(pszExtension, "tlk") == 0)
        return NwnResType_TLK;
    if (strcasecmp(pszExtension, "txi") == 0)
        return NwnResType_TXI;
    if (strcasecmp(pszExtension, "git") == 0)
        return NwnResType_GIT;
    if (strcasecmp(pszExtension, "bti") == 0)
        return NwnResType_BTI;
    if (strcasecmp(pszExtension, "uti") == 0)
        return NwnResType_UTI;
    if (strcasecmp(pszExtension, "btc") == 0)
        return NwnResType_BTC;
    if (strcasecmp(pszExtension, "utc") == 0)
        return NwnResType_UTC;
    if (strcasecmp(pszExtension, "dlg") == 0)
        return NwnResType_DLG;
    if (strcasecmp(pszExtension, "itp") == 0)
        return NwnResType_ITP;
    if (strcasecmp(pszExtension, "btt") == 0)
        return NwnResType_BTT;
    if (strcasecmp(pszExtension, "utt") == 0)
        return NwnResType_UTT;
    if (strcasecmp(pszExtension, "dds") == 0)
        return NwnResType_DDS;
    if (strcasecmp(pszExtension, "uts") == 0)
        return NwnResType_UTS;
    if (strcasecmp(pszExtension, "ltr") == 0)
        return NwnResType_LTR;
    if (strcasecmp(pszExtension, "gff") == 0)
        return NwnResType_GFF;
    if (strcasecmp(pszExtension, "fac") == 0)
        return NwnResType_FAC;
    if (strcasecmp(pszExtension, "bte") == 0)
        return NwnResType_BTE;
    if (strcasecmp(pszExtension, "ute") == 0)
        return NwnResType_UTE;
    if (strcasecmp(pszExtension, "btd") == 0)
        return NwnResType_BTD;
    if (strcasecmp(pszExtension, "utd") == 0)
        return NwnResType_UTD;
    if (strcasecmp(pszExtension, "btp") == 0)
        return NwnResType_BTP;
    if (strcasecmp(pszExtension, "utp") == 0)
        return NwnResType_UTP;
    if (strcasecmp(pszExtension, "dtf") == 0)
        return NwnResType_DTF;
    if (strcasecmp(pszExtension, "gic") == 0)
        return NwnResType_GIC;
    if (strcasecmp(pszExtension, "gui") == 0)
        return NwnResType_GUI;
    if (strcasecmp(pszExtension, "css") == 0)
        return NwnResType_CSS;
    if (strcasecmp(pszExtension, "ccs") == 0)
        return NwnResType_CCS;
    if (strcasecmp(pszExtension, "btm") == 0)
        return NwnResType_BTM;
    if (strcasecmp(pszExtension, "utm") == 0)
        return NwnResType_UTM;
    if (strcasecmp(pszExtension, "dwk") == 0)
        return NwnResType_DWK;
    if (strcasecmp(pszExtension, "pwk") == 0)
        return NwnResType_PWK;
    if (strcasecmp(pszExtension, "btg") == 0)
        return NwnResType_BTG;
    if (strcasecmp(pszExtension, "utg") == 0)
        return NwnResType_UTG;
    if (strcasecmp(pszExtension, "jrl") == 0)
        return NwnResType_JRL;
    if (strcasecmp(pszExtension, "sav") == 0)
        return NwnResType_SAV;
    if (strcasecmp(pszExtension, "utw") == 0)
        return NwnResType_UTW;
    if (strcasecmp(pszExtension, "4pc") == 0)
        return NwnResType_4PC;
    if (strcasecmp(pszExtension, "ssf") == 0)
        return NwnResType_SSF;
    if (strcasecmp(pszExtension, "hak") == 0)
        return NwnResType_HAK;
    if (strcasecmp(pszExtension, "nwm") == 0)
        return NwnResType_NWM;
    if (strcasecmp(pszExtension, "bik") == 0)
        return NwnResType_BIK;
    if (strcasecmp(pszExtension, "ndb") == 0)
        return NwnResType_NDB;
    if (strcasecmp(pszExtension, "erf") == 0)
        return NwnResType_ERF;
    if (strcasecmp(pszExtension, "bif") == 0)
        return NwnResType_BIF;
    if (strcasecmp(pszExtension, "key") == 0)
        return NwnResType_KEY;
    if (strcasecmp(pszExtension, "ptm") == 0)
        return NwnResType_PTM;
    if (strcasecmp(pszExtension, "ptt") == 0)
        return NwnResType_PTT;
    return NwnResType_Unknown;
}


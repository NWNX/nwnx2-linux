#ifndef ETS_NWNDEFINES_H
#define ETS_NWNDEFINES_H

//-----------------------------------------------------------------------------
//
// @doc
//
// @module  NwnDefines.h - Global definitions |
//
// This module contains the definition of the global values.
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
// $History: CnfMainWnd.h $
//
//-----------------------------------------------------------------------------

enum NwnResType {
    NwnResType_RES      = 0x0000,
    NwnResType_BMP      = 0x0001,
    NwnResType_MVE      = 0x0002,
    NwnResType_TGA      = 0x0003,
    NwnResType_WAV      = 0x0004,
    NwnResType_PLT      = 0x0006,
    NwnResType_INI      = 0x0007,
    NwnResType_BMU      = 0x0008,
    NwnResType_MPG      = 0x0009,
    NwnResType_TXT      = 0x000A,
    NwnResType_PLH      = 0x07D0,
    NwnResType_TEX      = 0x07D1,
    NwnResType_MDL      = 0x07D2,
    NwnResType_THG      = 0x07D3,
    NwnResType_FNT      = 0x07D5,
    NwnResType_LUA      = 0x07D7,
    NwnResType_SLT      = 0x07D8,
    NwnResType_NSS      = 0x07D9,
    NwnResType_NCS      = 0x07DA,
    NwnResType_MOD      = 0x07DB,
    NwnResType_ARE      = 0x07DC,
    NwnResType_SET      = 0x07DD,
    NwnResType_IFO      = 0x07DE,
    NwnResType_BIC      = 0x07DF,
    NwnResType_WOK      = 0x07E0,
    NwnResType_2DA      = 0x07E1,
    NwnResType_TLK      = 0x07E2,
    NwnResType_TXI      = 0x07E6,
    NwnResType_GIT      = 0x07E7,
    NwnResType_BTI      = 0x07E8,
    NwnResType_UTI      = 0x07E9,
    NwnResType_BTC      = 0x07EA,
    NwnResType_UTC      = 0x07EB,
    NwnResType_DLG      = 0x07ED,
    NwnResType_ITP      = 0x07EE,
    NwnResType_BTT      = 0x07EF,
    NwnResType_UTT      = 0x07F0,
    NwnResType_DDS      = 0x07F1,
    NwnResType_UTS      = 0x07F3,
    NwnResType_LTR      = 0x07F4,
    NwnResType_GFF      = 0x07F5,
    NwnResType_FAC      = 0x07F6,
    NwnResType_BTE      = 0x07F7,
    NwnResType_UTE      = 0x07F8,
    NwnResType_BTD      = 0x07F9,
    NwnResType_UTD      = 0x07FA,
    NwnResType_BTP      = 0x07FB,
    NwnResType_UTP      = 0x07FC,
    NwnResType_DTF      = 0x07FD,
    NwnResType_GIC      = 0x07FE,
    NwnResType_GUI      = 0x07FF,
    NwnResType_CSS      = 0x0800,
    NwnResType_CCS      = 0x0801,
    NwnResType_BTM      = 0x0802,
    NwnResType_UTM      = 0x0803,
    NwnResType_DWK      = 0x0804,
    NwnResType_PWK      = 0x0805,
    NwnResType_BTG      = 0x0806,
    NwnResType_UTG      = 0x0807,
    NwnResType_JRL      = 0x0808,
    NwnResType_SAV      = 0x0809,
    NwnResType_UTW      = 0x080A,
    NwnResType_4PC      = 0x080B,
    NwnResType_SSF      = 0x080C,
    NwnResType_HAK      = 0x080D,
    NwnResType_NWM      = 0x080E,
    NwnResType_BIK      = 0x080F,
    NwnResType_NDB      = 0x0810,
    NwnResType_PTM      = 0x0811,
    NwnResType_PTT      = 0x0812,
    NwnResType_ERF      = 0x270D,
    NwnResType_BIF      = 0x270E,
    NwnResType_KEY      = 0x270F,

    //
    // The following are not Bioware IDS but used internally
    // in this software
    //

    NwnResType_Unknown  = 0xFFFFFFFF,
};

enum NwnPalette {
    NwnPalette_Skin     = 0,
    NwnPalette_Hair     = 1,
    NwnPalette_Metal1   = 2,
    NwnPalette_Metal2   = 3,
    NwnPalette_Cloth1   = 4,
    NwnPalette_Cloth2   = 5,
    NwnPalette_Leather1 = 6,
    NwnPalette_Leather2 = 7,
    NwnPalette_Tattoo1  = 8,
    NwnPalette_Tattoo2  = 9,
    NwnPalette__Count   = 10,
};

enum NwnLanguage {
    NwnLanguage_English         = 0,
    NwnLanguage_French_Male     = 2,
    NwnLanguage_French_Female   = 3,
    NwnLanguage_German_Male     = 4,
    NwnLanguage_German_Female   = 5,
    NwnLanguage_Italian_Male    = 6,
    NwnLanguage_Italian_Female  = 7,
    NwnLanguage_Spanish_Male    = 8,
    NwnLanguage_Spanish_Female  = 9,
};

//-----------------------------------------------------------------------------
//
// Helper routines
//
//-----------------------------------------------------------------------------

const char *NwnGetResTypeExtension(NwnResType nType);
NwnResType NwnGetResTypeFromExtension(const char *pszExtension);

#endif // ETS_NWNDEFINES_H

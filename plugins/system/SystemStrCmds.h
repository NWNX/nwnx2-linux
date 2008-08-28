/* ANSI-C code produced by gperf version 3.0.3 */
/* Command-line: gperf -L ANSI-C -tCG -m 10 -K name -H SystemStrCommandHash -N SystemStrCommandLookup -W SystemStrCommandList --output-file=gperf.out SystemStrCmds.gperf  */
/* Computed positions: -k'1,5' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "SystemStrCmds.gperf"

/***************************************************************************
    NWNXSystem.h - Interface for the CNWNXSystem class.
    Copyright (C) 2007 Doug Swarin (zac@intertex.net)

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

#ifndef NWNX_SYSTEM_STRCMDS_H
#define NWNX_SYSTEM_STRCMDS_H

#ifdef __cplusplus
extern "C" {
#endif

#line 30 "SystemStrCmds.gperf"
struct SystemStrCommand_s {
    const char  *name;
    void       (*func)(CGameObject *, char *);
};

#define NWNX_SYSTEM_STRCMD_TOTAL_KEYWORDS 12
#define NWNX_SYSTEM_STRCMD_MIN_WORD_LENGTH 7
#define NWNX_SYSTEM_STRCMD_MAX_WORD_LENGTH 21
#define NWNX_SYSTEM_STRCMD_MIN_HASH_VALUE 8
#define NWNX_SYSTEM_STRCMD_MAX_HASH_VALUE 21
/* maximum key range = 14, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
SystemStrCommandHash (register const char *str, register unsigned int len)
{
  static const unsigned char asso_values[] =
    {
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22,  9,  1, 22,
       0,  0, 22,  1, 22, 22,  0,  2, 22, 22,
      22, 22,  0,  1, 22, 22, 22, 22, 22,  2,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22
    };
  return len + asso_values[(unsigned char)str[4]] + asso_values[(unsigned char)str[0]];
}

static const struct SystemStrCommand_s SystemStrCommandList[] =
  {
    {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 39 "SystemStrCmds.gperf"
    {"FILELINK",                               Func_FileLink},
#line 36 "SystemStrCmds.gperf"
    {"DIRLIST",                                Func_DirList},
#line 40 "SystemStrCmds.gperf"
    {"FILERENAME",                             Func_FileRename},
#line 38 "SystemStrCmds.gperf"
    {"FILEDELETE",                             Func_FileDelete},
#line 41 "SystemStrCmds.gperf"
    {"FILESYMLINK",                            Func_FileSymlink},
#line 45 "SystemStrCmds.gperf"
    {"GETTMILIMIT",                            Func_GetTMILimit},
#line 46 "SystemStrCmds.gperf"
    {"SETTMILIMIT",                            Func_SetTMILimit},
#line 44 "SystemStrCmds.gperf"
    {"GETSYSTEMTIME",                          Func_GetSystemTime},
#line 47 "SystemStrCmds.gperf"
    {"SHUTDOWNSERVER",                         Func_ShutdownServer},
#line 37 "SystemStrCmds.gperf"
    {"FILECOPY",                               Func_FileCopy},
#line 42 "SystemStrCmds.gperf"
    {"GETPROCESSCPUUSAGE",                     Func_GetProcessCPUUsage},
    {""}, {""},
#line 43 "SystemStrCmds.gperf"
    {"GETPROCESSMEMORYUSAGE",                  Func_GetProcessMemoryUsage}
  };

#ifdef __GNUC__
__inline
#ifdef __GNUC_STDC_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
static const struct SystemStrCommand_s *
SystemStrCommandLookup (register const char *str, register unsigned int len)
{
  if (len <= NWNX_SYSTEM_STRCMD_MAX_WORD_LENGTH && len >= NWNX_SYSTEM_STRCMD_MIN_WORD_LENGTH)
    {
      register int key = SystemStrCommandHash (str, len);

      if (key <= NWNX_SYSTEM_STRCMD_MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = SystemStrCommandList[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &SystemStrCommandList[key];
        }
    }
  return 0;
}
#line 48 "SystemStrCmds.gperf"


#ifdef __cplusplus
}
#endif

#endif /* NWNX_SYSTEM_STRCMDS_H */

/* vim: set sw=4: */

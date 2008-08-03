/* ANSI-C code produced by gperf version 3.0.1 */
/* Command-line: gperf -L ANSI-C -tCG -m 10 -K name -H FuncsObjCommandHash -N FuncsObjCommandLookup -W FuncsObjCommandList --output-file=gperf.out FuncsObjCmds.gperf  */
/* Computed positions: -k'' */

#line 1 "FuncsObjCmds.gperf"

/***************************************************************************
    NWNXFuncs.h - Interface for the CNWNXFuncs class.
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

#ifndef NWNX_EXALT_OBJCMDS_H
#define NWNX_EXALT_OBJCMDS_H

#ifdef __cplusplus
extern "C" {
#endif

#line 30 "FuncsObjCmds.gperf"
struct FuncsObjCommand_s {
    const char          *name;
    unsigned long       (*func)(CGameObject *);
};

#define NWNX_FUNCS_OBJCMD_TOTAL_KEYWORDS 1
#define NWNX_FUNCS_OBJCMD_MIN_WORD_LENGTH 56
#define NWNX_FUNCS_OBJCMD_MAX_WORD_LENGTH 56
#define NWNX_FUNCS_OBJCMD_MIN_HASH_VALUE 56
#define NWNX_FUNCS_OBJCMD_MAX_HASH_VALUE 56
/* maximum key range = 1, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
/*ARGSUSED*/
static unsigned int
FuncsObjCommandHash (register const char *str, register unsigned int len)
{
  return len;
}

static const struct FuncsObjCommand_s FuncsObjCommandList[] =
  {
    {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
    {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
    {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
    {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
    {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
    {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
    {""}, {""},
#line 36 "FuncsObjCmds.gperf"
    {"INTTOOBJECT                             Func_IntToObject"}
  };

#ifdef __GNUC__
__inline
#endif
static const struct FuncsObjCommand_s *
FuncsObjCommandLookup (register const char *str, register unsigned int len)
{
  if (len <= NWNX_FUNCS_OBJCMD_MAX_WORD_LENGTH && len >= NWNX_FUNCS_OBJCMD_MIN_WORD_LENGTH)
    {
      register int key = FuncsObjCommandHash (str, len);

      if (key <= NWNX_FUNCS_OBJCMD_MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = FuncsObjCommandList[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &FuncsObjCommandList[key];
        }
    }
  return 0;
}
#line 37 "FuncsObjCmds.gperf"


#ifdef __cplusplus
}
#endif

#endif /* NWNX_EXALT_OBJCMDS_H */

/* vim: set sw=4: */

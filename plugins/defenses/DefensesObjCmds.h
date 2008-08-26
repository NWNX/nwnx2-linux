/* ANSI-C code produced by gperf version 3.0.3 */
/* Command-line: gperf -L ANSI-C -tCG -m 10 -K name -H DefensesObjCommandHash -N DefensesObjCommandLookup -W DefensesObjCommandList --output-file=gperf.out DefensesObjCmds.gperf  */
/* Computed positions: -k'' */

#line 1 "DefensesObjCmds.gperf"

/***************************************************************************
    NWNXDefenses.h - Interface for the CNWNXDefenses class.
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

#ifndef NWNX_DEFENSES_OBJCMDS_H
#define NWNX_DEFENSES_OBJCMDS_H

#ifdef __cplusplus
extern "C" {
#endif

#line 30 "DefensesObjCmds.gperf"
struct DefensesObjCommand_s {
    const char          *name;
    nwn_objid_t        (*func)(CGameObject *);
};

#define NWNX_DEFENSES_OBJCMD_TOTAL_KEYWORDS 1
#define NWNX_DEFENSES_OBJCMD_MIN_WORD_LENGTH 11
#define NWNX_DEFENSES_OBJCMD_MAX_WORD_LENGTH 11
#define NWNX_DEFENSES_OBJCMD_MIN_HASH_VALUE 11
#define NWNX_DEFENSES_OBJCMD_MAX_HASH_VALUE 11
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
DefensesObjCommandHash (register const char *str, register unsigned int len)
{
  return len;
}

static const struct DefensesObjCommand_s DefensesObjCommandList[] =
  {
    {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
    {""}, {""},
#line 36 "DefensesObjCmds.gperf"
    {"INTTOOBJECT",                            Func_IntToObject}
  };

#ifdef __GNUC__
__inline
#ifdef __GNUC_STDC_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
static const struct DefensesObjCommand_s *
DefensesObjCommandLookup (register const char *str, register unsigned int len)
{
  if (len <= NWNX_DEFENSES_OBJCMD_MAX_WORD_LENGTH && len >= NWNX_DEFENSES_OBJCMD_MIN_WORD_LENGTH)
    {
      register int key = DefensesObjCommandHash (str, len);

      if (key <= NWNX_DEFENSES_OBJCMD_MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = DefensesObjCommandList[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &DefensesObjCommandList[key];
        }
    }
  return 0;
}
#line 37 "DefensesObjCmds.gperf"


#ifdef __cplusplus
}
#endif

#endif /* NWNX_DEFENSES_OBJCMDS_H */

/* vim: set sw=4: */

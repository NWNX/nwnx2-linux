/* ANSI-C code produced by gperf version 3.0.1 */
/* Command-line: gperf -L ANSI-C -tCG -m 10 -K name -H FuncsStrCommandHash -N FuncsStrCommandLookup -W FuncsStrCommandList --output-file=gperf.out FuncsStrCmds.gperf  */
/* Computed positions: -k'1,4,8' */

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

#line 1 "FuncsStrCmds.gperf"

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

#ifndef NWNX_FUNCS_STRCMDS_H
#define NWNX_FUNCS_STRCMDS_H

#ifdef __cplusplus
extern "C" {
#endif

#line 30 "FuncsStrCmds.gperf"
struct FuncsStrCommand_s {
    const char  *name;
    void       (*func)(CGameObject *, char *);
};

#define NWNX_FUNCS_STRCMD_TOTAL_KEYWORDS 95
#define NWNX_FUNCS_STRCMD_MIN_WORD_LENGTH 6
#define NWNX_FUNCS_STRCMD_MAX_WORD_LENGTH 26
#define NWNX_FUNCS_STRCMD_MIN_HASH_VALUE 19
#define NWNX_FUNCS_STRCMD_MAX_HASH_VALUE 158
/* maximum key range = 140, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
FuncsStrCommandHash (register const char *str, register unsigned int len)
{
  static const unsigned char asso_values[] =
    {
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159,  14,  42,  44,   2,  79,
       43,   2, 159,  38,   8,   7,   2,  50,  14,  25,
       67,   4,  20,   4,  30,   3, 159,  23, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159, 159, 159, 159, 159,
      159, 159, 159, 159, 159, 159
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[7]];
      /*FALLTHROUGH*/
      case 7:
      case 6:
      case 5:
      case 4:
        hval += asso_values[(unsigned char)str[3]];
      /*FALLTHROUGH*/
      case 3:
      case 2:
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

static const struct FuncsStrCommand_s FuncsStrCommandList[] =
  {
    {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
    {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
    {""},
#line 79 "FuncsStrCmds.gperf"
    {"GETSOUNDSET",                           Func_GetSoundset},
    {""},
#line 126 "FuncsStrCmds.gperf"
    {"SETSOUNDSET",                           Func_SetSoundset},
#line 125 "FuncsStrCmds.gperf"
    {"SETSKILLRANK",                          Func_SetSkillRank},
#line 53 "FuncsStrCmds.gperf"
    {"GETDAMAGEIMMUNITY",                     Func_GetDamageImmunity},
    {""},
#line 63 "FuncsStrCmds.gperf"
    {"GETKNOWSFEAT",                          Func_GetKnowsFeat},
#line 64 "FuncsStrCmds.gperf"
    {"GETKNOWSSPELL",                         Func_GetKnowsSpell},
#line 66 "FuncsStrCmds.gperf"
    {"GETLOCALVARIABLECOUNT",                 Func_GetLocalVariableCount},
#line 74 "FuncsStrCmds.gperf"
    {"GETQUICKBARSLOT",                       Func_GetQuickBarSlot},
    {""},
#line 121 "FuncsStrCmds.gperf"
    {"SETQUICKBARSLOT",                       Func_SetQuickBarSlot},
#line 78 "FuncsStrCmds.gperf"
    {"GETSKILLINCREASEBYLEVEL",               Func_GetSkillIncreaseByLevel},
#line 65 "FuncsStrCmds.gperf"
    {"GETLOCALVARIABLEBYPOSITION",            Func_GetLocalVariableByPosition},
#line 56 "FuncsStrCmds.gperf"
    {"GETGROUNDHEIGHT",                       Func_GetGroundHeight},
    {""},
#line 60 "FuncsStrCmds.gperf"
    {"GETKNOWNFEAT",                          Func_GetKnownFeat},
#line 62 "FuncsStrCmds.gperf"
    {"GETKNOWNSPELL",                         Func_GetKnownSpell},
#line 111 "FuncsStrCmds.gperf"
    {"SETKNOWNFEAT",                          Func_SetKnownFeat},
#line 113 "FuncsStrCmds.gperf"
    {"SETKNOWNSPELL",                         Func_SetKnownSpell},
#line 77 "FuncsStrCmds.gperf"
    {"GETSAVINGTHROWBONUS",                   Func_GetSavingThrowBonus},
#line 128 "FuncsStrCmds.gperf"
    {"SETTAG",                                Func_SetTag},
#line 124 "FuncsStrCmds.gperf"
    {"SETSAVINGTHROWBONUS",                   Func_SetSavingThrowBonus},
#line 61 "FuncsStrCmds.gperf"
    {"GETKNOWNFEATBYLEVEL",                   Func_GetKnownFeatByLevel},
    {""},
#line 112 "FuncsStrCmds.gperf"
    {"SETKNOWNFEATBYLEVEL",                   Func_SetKnownFeatByLevel},
#line 96 "FuncsStrCmds.gperf"
    {"REPLACEKNOWNFEAT",                      Func_ReplaceKnownFeat},
#line 97 "FuncsStrCmds.gperf"
    {"REPLACEKNOWNSPELL",                     Func_ReplaceKnownSpell},
#line 37 "FuncsStrCmds.gperf"
    {"ADDKNOWNFEAT",                          Func_AddKnownFeat},
#line 39 "FuncsStrCmds.gperf"
    {"ADDKNOWNSPELL",                         Func_AddKnownSpell},
#line 102 "FuncsStrCmds.gperf"
    {"SETALIGNMENTVALUE",                     Func_SetAlignmentValue},
#line 81 "FuncsStrCmds.gperf"
    {"GETTOTALFEATUSES",                      Func_GetTotalFeatUses},
#line 122 "FuncsStrCmds.gperf"
    {"SETRACIALTYPE",                         Func_SetRacialType},
#line 82 "FuncsStrCmds.gperf"
    {"GETTOTALKNOWNFEATS",                    Func_GetTotalKnownFeats},
#line 84 "FuncsStrCmds.gperf"
    {"GETTOTALKNOWNSPELLS",                   Func_GetTotalKnownSpells},
#line 38 "FuncsStrCmds.gperf"
    {"ADDKNOWNFEATATLEVEL",                   Func_AddKnownFeatAtLevel},
#line 57 "FuncsStrCmds.gperf"
    {"GETISWALKABLE",                         Func_GetIsWalkable},
    {""}, {""},
#line 85 "FuncsStrCmds.gperf"
    {"GETTOTALSPECIALABILITIES",              Func_GetTotalSpecialAbilities},
#line 83 "FuncsStrCmds.gperf"
    {"GETTOTALKNOWNFEATSBYLEVEL",             Func_GetTotalKnownFeatsByLevel},
    {""},
#line 80 "FuncsStrCmds.gperf"
    {"GETSPECIALABILITY",                     Func_GetSpecialAbility},
#line 43 "FuncsStrCmds.gperf"
    {"GETACNATURALBASE",                      Func_GetACNaturalBase},
#line 127 "FuncsStrCmds.gperf"
    {"SETSPECIALABILITY",                     Func_SetSpecialAbility},
#line 100 "FuncsStrCmds.gperf"
    {"SETACNATURALBASE",                      Func_SetACNaturalBase},
#line 48 "FuncsStrCmds.gperf"
    {"GETCLASSBYLEVEL",                       Func_GetClassByLevel},
#line 47 "FuncsStrCmds.gperf"
    {"GETBONUSSPELLSLOTS",                    Func_GetBonusSpellSlots},
    {""},
#line 86 "FuncsStrCmds.gperf"
    {"GETWIZARDSPECIALIZATION",               Func_GetWizardSpecialization},
#line 36 "FuncsStrCmds.gperf"
    {"ACTIONUSEITEM",                         Func_ActionUseItem},
#line 130 "FuncsStrCmds.gperf"
    {"SETWIZARDSPECIALIZATION",               Func_SetWizardSpecialization},
#line 101 "FuncsStrCmds.gperf"
    {"SETABILITYSCORE",                       Func_SetAbilityScore},
    {""},
#line 40 "FuncsStrCmds.gperf"
    {"ADDSPECIALABILITY",                     Func_AddSpecialAbility},
#line 92 "FuncsStrCmds.gperf"
    {"REMOVEKNOWNFEAT",                       Func_RemoveKnownFeat},
#line 94 "FuncsStrCmds.gperf"
    {"REMOVEKNOWNSPELL",                      Func_RemoveKnownSpell},
    {""}, {""},
#line 110 "FuncsStrCmds.gperf"
    {"SETITEMWEIGHT",                         Func_SetItemWeight},
#line 44 "FuncsStrCmds.gperf"
    {"GETABILITYINCREASEBYLEVEL",             Func_GetAbilityIncreaseByLevel},
#line 75 "FuncsStrCmds.gperf"
    {"GETREMAININGFEATUSES",                  Func_GetRemainingFeatUses},
#line 93 "FuncsStrCmds.gperf"
    {"REMOVEKNOWNFEATBYLEVEL",                Func_RemoveKnownFeatByLevel},
#line 76 "FuncsStrCmds.gperf"
    {"GETREMAININGSPELLSLOTS",                Func_GetRemainingSpellSlots},
#line 70 "FuncsStrCmds.gperf"
    {"GETPCBODYBAG",                          Func_GetPCBodyBag},
#line 123 "FuncsStrCmds.gperf"
    {"SETREMAININGSPELLSLOTS",                Func_SetRemainingSpellSlots},
#line 117 "FuncsStrCmds.gperf"
    {"SETPCBODYBAG",                          Func_SetPCBodyBag},
    {""},
#line 98 "FuncsStrCmds.gperf"
    {"RESTOREREADYFEATS",                     Func_RestoreReadyFeats},
#line 99 "FuncsStrCmds.gperf"
    {"RESTOREREADYSPELLS",                    Func_RestoreReadySpells},
#line 69 "FuncsStrCmds.gperf"
    {"GETMEMORIZEDSPELL",                     Func_GetMemorizedSpell},
#line 109 "FuncsStrCmds.gperf"
    {"SETGOLDPIECEVALUE",                     Func_SetGoldPieceValue},
#line 115 "FuncsStrCmds.gperf"
    {"SETMEMORIZEDSPELL",                     Func_SetMemorizedSpell},
#line 129 "FuncsStrCmds.gperf"
    {"SETTRAPCREATOR",                        Func_SetTrapCreator},
#line 105 "FuncsStrCmds.gperf"
    {"SETCREATURESIZE",                       Func_SetCreatureSize},
#line 87 "FuncsStrCmds.gperf"
    {"INTTOOBJECTREQUEST",                    Func_IntToObjectRequest},
#line 55 "FuncsStrCmds.gperf"
    {"GETFACTIONID",                          Func_GetFactionId},
#line 59 "FuncsStrCmds.gperf"
    {"GETITEMCOUNT",                          Func_GetItemCount},
#line 108 "FuncsStrCmds.gperf"
    {"SETFACTIONID",                          Func_SetFactionId},
#line 71 "FuncsStrCmds.gperf"
    {"GETPCPORT",                             Func_GetPCPort},
#line 49 "FuncsStrCmds.gperf"
    {"GETCLERICDOMAIN",                       Func_GetClericDomain},
#line 73 "FuncsStrCmds.gperf"
    {"GETPORTRAIT",                           Func_GetPortrait},
#line 103 "FuncsStrCmds.gperf"
    {"SETCLERICDOMAIN",                       Func_SetClericDomain},
#line 120 "FuncsStrCmds.gperf"
    {"SETPORTRAIT",                           Func_SetPortrait},
#line 52 "FuncsStrCmds.gperf"
    {"GETCRITICALHITRANGE",                   Func_GetCriticalHitRange},
    {""}, {""},
#line 58 "FuncsStrCmds.gperf"
    {"GETITEMBYPOSITIONREQUEST",              Func_GetItemByPositionRequest},
    {""},
#line 51 "FuncsStrCmds.gperf"
    {"GETCRITICALHITMULTIPLIER",              Func_GetCriticalHitMultiplier},
#line 118 "FuncsStrCmds.gperf"
    {"SETPCLOOTABLE",                         Func_SetPCLootable},
#line 91 "FuncsStrCmds.gperf"
    {"MODIFYSKILLRANK",                       Func_ModifySkillRank},
    {""},
#line 67 "FuncsStrCmds.gperf"
    {"GETMAXHITPOINTSBYLEVEL",                Func_GetMaxHitPointsByLevel},
#line 90 "FuncsStrCmds.gperf"
    {"MODIFYCURRENTHITPOINTS",                Func_ModifyCurrentHitPoints},
#line 114 "FuncsStrCmds.gperf"
    {"SETMAXHITPOINTSBYLEVEL",                Func_SetMaxHitPointsByLevel},
    {""},
#line 45 "FuncsStrCmds.gperf"
    {"GETALLMEMORIZEDSPELLS",                 Func_GetAllMemorizedSpells},
    {""},
#line 46 "FuncsStrCmds.gperf"
    {"GETALLREMAININGFEATUSES",               Func_GetAllRemainingFeatUses},
#line 116 "FuncsStrCmds.gperf"
    {"SETMOVEMENTRATE",                       Func_SetMovementRate},
    {""}, {""}, {""},
#line 72 "FuncsStrCmds.gperf"
    {"GETPCSKILLPOINTS",                      Func_GetPCSkillPoints},
#line 88 "FuncsStrCmds.gperf"
    {"JUMPTOLIMBO",                           Func_JumpToLimbo},
#line 119 "FuncsStrCmds.gperf"
    {"SETPCSKILLPOINTS",                      Func_SetPCSkillPoints},
#line 54 "FuncsStrCmds.gperf"
    {"GETEVENTHANDLER",                       Func_GetEventHandler},
#line 41 "FuncsStrCmds.gperf"
    {"BOOTPCWITHMESSAGE",                     Func_BootPCWithMessage},
#line 107 "FuncsStrCmds.gperf"
    {"SETEVENTHANDLER",                       Func_SetEventHandler},
    {""}, {""}, {""},
#line 95 "FuncsStrCmds.gperf"
    {"REMOVESPECIALABILITY",                  Func_RemoveSpecialAbility},
    {""}, {""},
#line 68 "FuncsStrCmds.gperf"
    {"GETMAXSPELLSLOTS",                      Func_GetMaxSpellSlots},
    {""}, {""}, {""}, {""},
#line 50 "FuncsStrCmds.gperf"
    {"GETCONVERSATION",                       Func_GetConversation},
    {""},
#line 104 "FuncsStrCmds.gperf"
    {"SETCONVERSATION",                       Func_SetConversation},
    {""}, {""}, {""},
#line 106 "FuncsStrCmds.gperf"
    {"SETCURRENTHITPOINTS",                   Func_SetCurrentHitPoints},
    {""},
#line 89 "FuncsStrCmds.gperf"
    {"MODIFYABILITYSCORE",                    Func_ModifyAbilityScore},
    {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 42 "FuncsStrCmds.gperf"
    {"DUMPOBJECT",                            Func_DumpObject}
  };

#ifdef __GNUC__
__inline
#endif
static const struct FuncsStrCommand_s *
FuncsStrCommandLookup (register const char *str, register unsigned int len)
{
  if (len <= NWNX_FUNCS_STRCMD_MAX_WORD_LENGTH && len >= NWNX_FUNCS_STRCMD_MIN_WORD_LENGTH)
    {
      register int key = FuncsStrCommandHash (str, len);

      if (key <= NWNX_FUNCS_STRCMD_MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = FuncsStrCommandList[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &FuncsStrCommandList[key];
        }
    }
  return 0;
}
#line 131 "FuncsStrCmds.gperf"


#ifdef __cplusplus
}
#endif

#endif /* NWNX_FUNCS_STRCMDS_H */

/* vim: set sw=4: */

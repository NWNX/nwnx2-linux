/* ANSI-C code produced by gperf version 3.0.3 */
/* Command-line: gperf -L ANSI-C -tG -m 10 -K name -H oo_hash -N oo_lookup -W oo_list --output-file=gperf.out openoverride.gperf  */
/* Computed positions: -k'10-11,14,16-18,21-22' */

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

#line 1 "openoverride.gperf"

#ifndef OPENOVERRIDE_H
#define OPENOVERRIDE_H

#ifdef __cplusplus
extern "C" {
#endif

#line 11 "openoverride.gperf"
struct openoverride_file_s {
  const char   *name;
  int           fd;
  int           module;
  FILE         *file;
  struct stat   sb;
};

#define OPENOVERRIDE_HASH_TOTAL_KEYWORDS 79
#define OPENOVERRIDE_HASH_MIN_WORD_LENGTH 12
#define OPENOVERRIDE_HASH_MAX_WORD_LENGTH 49
#define OPENOVERRIDE_HASH_MIN_HASH_VALUE 16
#define OPENOVERRIDE_HASH_MAX_HASH_VALUE 123
/* maximum key range = 108, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
oo_hash (register const char *str, register unsigned int len)
{
  static unsigned char asso_values[] =
    {
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124,   3, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124,   2,   3,  44,   3,
        2,  10,  25,   6,   4, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
        2, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124,   5, 124,  28,  16,  35,
        3,  16,   2,   3,   2,   6, 124,   2,   2,  31,
       33,   5,  10, 124,   3,  15,   2,  48,  13, 124,
        2, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124, 124, 124, 124, 124,
      124, 124, 124, 124, 124, 124
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[21]];
      /*FALLTHROUGH*/
      case 21:
        hval += asso_values[(unsigned char)str[20]];
      /*FALLTHROUGH*/
      case 20:
      case 19:
      case 18:
        hval += asso_values[(unsigned char)str[17]];
      /*FALLTHROUGH*/
      case 17:
        hval += asso_values[(unsigned char)str[16]];
      /*FALLTHROUGH*/
      case 16:
        hval += asso_values[(unsigned char)str[15]];
      /*FALLTHROUGH*/
      case 15:
      case 14:
        hval += asso_values[(unsigned char)str[13]];
      /*FALLTHROUGH*/
      case 13:
      case 12:
      case 11:
        hval += asso_values[(unsigned char)str[10]];
      /*FALLTHROUGH*/
      case 10:
        hval += asso_values[(unsigned char)str[9]];
        break;
    }
  return hval;
}

static struct openoverride_file_s oo_list[] =
  {
    { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } },
    { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } },
    { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } },
    { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } },
    { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } },
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 62 "openoverride.gperf"
    {"./dialog.tlk",                                      -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } },
#line 53 "openoverride.gperf"
    {"./data/xp2.bif",                                    -1, -1, NULL, { .st_dev = 0 }},
#line 46 "openoverride.gperf"
    {"./data/xp1.bif",                                    -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } },
#line 35 "openoverride.gperf"
    {"./data/ini.bif",                                    -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } },
#line 90 "openoverride.gperf"
    {"./tlk/dialog.tlk",                                  -1, -1, NULL, { .st_dev = 0 }},
#line 61 "openoverride.gperf"
    {"./data/xp3.bif",                                    -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 91 "openoverride.gperf"
    {"./tlk/cep2_v1.tlk",                                 -1, -1, NULL, { .st_dev = 0 }},
#line 96 "openoverride.gperf"
    {"./tlk/cep22_v1.tlk",                                -1, -1, NULL, { .st_dev = 0 }},
#line 95 "openoverride.gperf"
    {"./tlk/cep21_v1.tlk",                                -1, -1, NULL, { .st_dev = 0 }},
#line 93 "openoverride.gperf"
    {"./tlk/cep2_v22.tlk",                                -1, -1, NULL, { .st_dev = 0 }},
#line 92 "openoverride.gperf"
    {"./tlk/cep2_v21.tlk",                                -1, -1, NULL, { .st_dev = 0 }},
#line 34 "openoverride.gperf"
    {"./data/editor.bif",                                 -1, -1, NULL, { .st_dev = 0 }},
#line 79 "openoverride.gperf"
    {"./hak/cep2_core2.hak",                              -1, -1, NULL, { .st_dev = 0 }},
#line 78 "openoverride.gperf"
    {"./hak/cep2_core1.hak",                              -1, -1, NULL, { .st_dev = 0 }},
#line 83 "openoverride.gperf"
    {"./hak/cep2_core6.hak",                              -1, -1, NULL, { .st_dev = 0 }},
#line 97 "openoverride.gperf"
    {"./tlk/cep23_v1.tlk",                                -1, -1, NULL, { .st_dev = 0 }},
#line 82 "openoverride.gperf"
    {"./hak/cep2_core5.hak",                              -1, -1, NULL, { .st_dev = 0 }},
#line 94 "openoverride.gperf"
    {"./tlk/cep2_v23.tlk",                                -1, -1, NULL, { .st_dev = 0 }},
#line 32 "openoverride.gperf"
    {"./data/aurora_ttf.bif",                             -1, -1, NULL, { .st_dev = 0 }},
#line 33 "openoverride.gperf"
    {"./data/aurora_ttr.bif",                             -1, -1, NULL, { .st_dev = 0 }},
#line 80 "openoverride.gperf"
    {"./hak/cep2_core3.hak",                              -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 22 "openoverride.gperf"
    {"./data/2da.bif",                                    -1, -1, NULL, { .st_dev = 0 }},
#line 76 "openoverride.gperf"
    {"./hak/cep2_ext_tiles.hak",                          -1, -1, NULL, { .st_dev = 0 }},
#line 73 "openoverride.gperf"
    {"./hak/cep2_add_tiles.hak",                          -1, -1, NULL, { .st_dev = 0 }},
#line 75 "openoverride.gperf"
    {"./hak/cep2_add_tiles2.hak",                         -1, -1, NULL, { .st_dev = 0 }},
#line 74 "openoverride.gperf"
    {"./hak/cep2_add_tiles1.hak",                         -1, -1, NULL, { .st_dev = 0 }},
#line 69 "openoverride.gperf"
    {"./hak/cep2_add_doors.hak",                          -1, -1, NULL, { .st_dev = 0 }},
#line 54 "openoverride.gperf"
    {"./data/xp2_models.bif",                             -1, -1, NULL, { .st_dev = 0 }},
#line 47 "openoverride.gperf"
    {"./data/xp1_models.bif",                             -1, -1, NULL, { .st_dev = 0 }},
#line 98 "openoverride.gperf"
    {"./tlk/cep24_v1.tlk",                                -1, -1, NULL, { .st_dev = 0 }},
#line 39 "openoverride.gperf"
    {"./data/music.bif",                                  -1, -1, NULL, { .st_dev = 0 }},
#line 28 "openoverride.gperf"
    {"./data/aurora_tds.bif",                             -1, -1, NULL, { .st_dev = 0 }},
#line 26 "openoverride.gperf"
    {"./data/aurora_tde.bif",                             -1, -1, NULL, { .st_dev = 0 }},
#line 85 "openoverride.gperf"
    {"./hak/cep2_top_v1.hak",                             -1, -1, NULL, { .st_dev = 0 }},
#line 81 "openoverride.gperf"
    {"./hak/cep2_core4.hak",                              -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 72 "openoverride.gperf"
    {"./hak/cep2_add_skies.hak",                          -1, -1, NULL, { .st_dev = 0 }},
#line 59 "openoverride.gperf"
    {"./data/xp2_tiles.bif",                              -1, -1, NULL, { .st_dev = 0 }},
#line 52 "openoverride.gperf"
    {"./data/xp1_tiles.bif",                              -1, -1, NULL, { .st_dev = 0 }},
#line 38 "openoverride.gperf"
    {"./data/models_02.bif",                              -1, -1, NULL, { .st_dev = 0 }},
#line 37 "openoverride.gperf"
    {"./data/models_01.bif",                              -1, -1, NULL, { .st_dev = 0 }},
#line 40 "openoverride.gperf"
    {"./data/scripts.bif",                                -1, -1, NULL, { .st_dev = 0 }},
#line 55 "openoverride.gperf"
    {"./data/xp2_scripts.bif",                            -1, -1, NULL, { .st_dev = 0 }},
#line 48 "openoverride.gperf"
    {"./data/xp1_scripts.bif",                            -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } },
#line 36 "openoverride.gperf"
    {"./data/misc.bif",                                   -1, -1, NULL, { .st_dev = 0 }},
#line 27 "openoverride.gperf"
    {"./data/aurora_tdm.bif",                             -1, -1, NULL, { .st_dev = 0 }},
#line 70 "openoverride.gperf"
    {"./hak/cep2_add_loads.hak",                          -1, -1, NULL, { .st_dev = 0 }},
#line 68 "openoverride.gperf"
    {"./hak/cep2_add_sb_v1.hak",                          -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 25 "openoverride.gperf"
    {"./data/aurora_tdc.bif",                             -1, -1, NULL, { .st_dev = 0 }},
#line 30 "openoverride.gperf"
    {"./data/aurora_tin.bif",                             -1, -1, NULL, { .st_dev = 0 }},
#line 77 "openoverride.gperf"
    {"./hak/cep2_core0.hak",                              -1, -1, NULL, { .st_dev = 0 }},
#line 29 "openoverride.gperf"
    {"./data/aurora_tic.bif",                             -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 64 "openoverride.gperf"
    {"./hak/cep2_add_phenos2.hak",                        -1, -1, NULL, { .st_dev = 0 }},
#line 63 "openoverride.gperf"
    {"./hak/cep2_add_phenos1.hak",                        -1, -1, NULL, { .st_dev = 0 }},
#line 84 "openoverride.gperf"
    {"./hak/cep2_custom.hak",                             -1, -1, NULL, { .st_dev = 0 }},
#line 31 "openoverride.gperf"
    {"./data/aurora_tms.bif",                             -1, -1, NULL, { .st_dev = 0 }},
#line 67 "openoverride.gperf"
    {"./hak/cep2_add_phenos5.hak",                        -1, -1, NULL, { .st_dev = 0 }},
#line 87 "openoverride.gperf"
    {"./hak/cep2_top_v22.hak",                            -1, -1, NULL, { .st_dev = 0 }},
#line 86 "openoverride.gperf"
    {"./hak/cep2_top_v21.hak",                            -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 65 "openoverride.gperf"
    {"./hak/cep2_add_phenos3.hak",                        -1, -1, NULL, { .st_dev = 0 }},
#line 60 "openoverride.gperf"
    {"./data/xp2patch.bif",                               -1, -1, NULL, { .st_dev = 0 }},
#line 71 "openoverride.gperf"
    {"./hak/cep2_add_rules.hak",                          -1, -1, NULL, { .st_dev = 0 }},
#line 23 "openoverride.gperf"
    {"./data/aurora_gui.bif",                             -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 88 "openoverride.gperf"
    {"./hak/cep2_top_v23.hak",                            -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 42 "openoverride.gperf"
    {"./data/templates.bif",                              -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 56 "openoverride.gperf"
    {"./data/xp2_sounds.bif",                             -1, -1, NULL, { .st_dev = 0 }},
#line 49 "openoverride.gperf"
    {"./data/xp1_sounds.bif",                             -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 44 "openoverride.gperf"
    {"./data/textures_02.bif",                            -1, -1, NULL, { .st_dev = 0 }},
#line 43 "openoverride.gperf"
    {"./data/textures_01.bif",                            -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 66 "openoverride.gperf"
    {"./hak/cep2_add_phenos4.hak",                        -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 24 "openoverride.gperf"
    {"./data/aurora_tcn.bif",                             -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 41 "openoverride.gperf"
    {"./data/sounds.bif",                                 -1, -1, NULL, { .st_dev = 0 }},
#line 89 "openoverride.gperf"
    {"./hak/cep2_top_v24.hak",                            -1, -1, NULL, { .st_dev = 0 }},
#line 45 "openoverride.gperf"
    {"./data/voicesets.bif",                              -1, -1, NULL, { .st_dev = 0 }},
#line 20 "openoverride.gperf"
    {"./modules/Path of Ascension CEP Legends.mod",       -1,  1, NULL, { .st_dev = 0 }},
#line 57 "openoverride.gperf"
    {"./data/xp2_templates.bif",                          -1, -1, NULL, { .st_dev = 0 }},
#line 50 "openoverride.gperf"
    {"./data/xp1_templates.bif",                          -1, -1, NULL, { .st_dev = 0 }},
    { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } },
    { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } }, { "", -1, -1, NULL, { .st_dev = 0 } },
    { "", -1, -1, NULL, { .st_dev = 0 } },
#line 58 "openoverride.gperf"
    {"./data/xp2_textures.bif",                           -1, -1, NULL, { .st_dev = 0 }},
#line 51 "openoverride.gperf"
    {"./data/xp1_textures.bif",                           -1, -1, NULL, { .st_dev = 0 }},
#line 21 "openoverride.gperf"
    {"./currentgame.0/Path of Ascension CEP Legends.mod", -1,  0, NULL, { .st_dev = 0 }}
  };

#ifdef __GNUC__
__inline
#ifdef __GNUC_STDC_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
struct openoverride_file_s *
oo_lookup (register const char *str, register unsigned int len)
{
  if (len <= OPENOVERRIDE_HASH_MAX_WORD_LENGTH && len >= OPENOVERRIDE_HASH_MIN_WORD_LENGTH)
    {
      register int key = oo_hash (str, len);

      if (key <= OPENOVERRIDE_HASH_MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = oo_list[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &oo_list[key];
        }
    }
  return 0;
}
#line 99 "openoverride.gperf"


#ifdef __cplusplus
}
#endif

#endif /* OPENOVERRIDE_H */

/* vim: set sw=4: */

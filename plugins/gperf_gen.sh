#!/bin/sh

V=$1
K=$2
L=$3

gperf -L ANSI-C -tCG -m 10 -K name -H ${V}CommandHash \
	-N ${V}CommandLookup -W ${V}CommandList \
	"${V}Cmds.gperf" --output-file="gperf.out"

sed -i 's/\<\(\(MIN\|MAX\)_\(WORD_LENGTH\|HASH_VALUE\)\|TOTAL_KEYWORDS\)\>/NWNX_'$K'_'$L'CMD_\1/g' \
	"gperf.out" || rm -f "gperf.out"

sed -i 's/^const struct/static const struct/' "gperf.out" || rm -f "gperf.out"

sed -i 's/|| defined __GNUC_GNU_INLINE__//' "gperf.out" || rm -f "gperf.out"

sed -i 's/defined __GNUC_STDC_INLINE__/0/' "gperf.out" || rm -f "gperf.out"

sed -i 's/__attribute__ ((__gnu_inline__))//' "gperf.out" || rm -f "gperf.out"

sed -i 's/{""}/{"", NULL}/g' "gperf.out" || rm -f "gperf.out"

mv "gperf.out" "${V}Cmds.h"

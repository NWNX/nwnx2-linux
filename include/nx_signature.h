/*
 *  NWNeXalt - Empty File
 *  (c) 2007 Doug Swarin (zac@intertex.net)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 *  $HeadURL$
 *
 */

#ifndef _NX_SIGNATURE_H_
#define _NX_SIGNATURE_H_

#define NX_NWN_SEARCH_START     0x08048000
#define NX_NWN_SEARCH_END       0x083c0000

#define NX_SIG_FLAG_WILD        0x01000000
#define NX_SIG_FLAG_MASK        0x02000000
#define NX_SIG_FLAG_RANGE       0x04000000
#define NX_SIG_FLAG_OR          0x08000000
#define NX_SIG_INVALID          0xFFFFFFFF


struct nx_sig_search_state_s;
struct nx_sig_search_engine_s;

typedef struct nx_sig_search_engine_s   nx_sig_search_t;

typedef void (*nx_sig_callback_f)(int, void *);




struct nx_sig_search_node_s {
    uint32_t                            nxsn_match;

    struct nx_sig_search_state_s       *nxsn_next;
};

struct nx_sig_search_state_s {
    int                                 nxss_id;

    size_t                              nxss_count;
    struct nx_sig_search_node_s        *nxss_nodes;
};

struct nx_sig_search_cursor_s {
    int                                 nxsc_active;
    size_t                              nxsc_depth;

    struct nx_sig_search_state_s       *nxsc_state;
};

struct nx_sig_search_engine_s {
    nx_sig_callback_f                   nxse_callback;

    struct nx_sig_search_state_s       *nxse_root;
};


#ifdef __cplusplus
extern "C" {
#endif

nx_sig_search_t *nx_sig_search_create(nx_sig_callback_f);
void nx_sig_search_destroy(nx_sig_search_t *);

int nx_sig_search_add_signature(nx_sig_search_t *, int, const char *);

int nx_sig_search_run(nx_sig_search_t *);

void *nx_sig_search(const char *);

#ifdef __cplusplus
}
#endif

#endif /* _NX_SIGNATURE_H_ */

/* vim: set sw=4: */

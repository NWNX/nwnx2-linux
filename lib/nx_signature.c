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

#include "NWNXLib.h"

/*! Match a search expression against a byte
 *
 */
static bool nx_sig_search_match(int p, uint32_t match)
{
    if (match & NX_SIG_FLAG_WILD)
        return true;

    if (match & NX_SIG_FLAG_OR) {
        if (((match >> 8) & 0xFF) && p == ((match >> 8) & 0xFF))
            return true;

        if (((match >> 16) & 0xFF) && p == ((match >> 16) & 0xFF))
            return true;
    }

    return (p == (match & 0xFF));
}


/*! Create a new search engine
 *
 */
nx_sig_search_t *nx_sig_search_create(nx_sig_callback_f cb)
{
    nx_sig_search_t *eng;

    eng = nx_safe_calloc(1, sizeof(*eng));

    eng->nxse_callback = cb;
    eng->nxse_root     = nx_safe_calloc(1, sizeof(struct nx_sig_search_state_s));

    return eng;
}


/*! Destroy an existing search engine
 *
 */
static int nx_sig_search_destroy_nodes(size_t count, struct nx_sig_search_node_s *nodes)
{
    int i, total = 0;

    for (i = 0; i < count; i++) {
        if (nodes[i].nxsn_next->nxss_count > 0)
            total += nx_sig_search_destroy_nodes(nodes[i].nxsn_next->nxss_count,
                                                 nodes[i].nxsn_next->nxss_nodes);

        nx_safe_free(nodes[i].nxsn_next);
    }

    if (count > 0)
        nx_safe_free(nodes);

    return (total + count);
}

void nx_sig_search_destroy(nx_sig_search_t *eng)
{
    nx_sig_search_destroy_nodes(eng->nxse_root->nxss_count, eng->nxse_root->nxss_nodes);
    nx_safe_free(eng->nxse_root);
    nx_safe_free(eng);
}


/*! Add a new signature to an existing search engine
 *
 */
int nx_sig_search_add_signature(nx_sig_search_t *eng, int id, const char *sig)
{
    int i, j, b1, b2, b3, count;
    bool skip;
    char *p, *q, *r, *copy;
    struct nx_sig_search_state_s *state = eng->nxse_root;

    copy = nx_safe_strdup(sig);

    for (q = copy, p = strsep(&q, " "); p; p = strsep(&q, " ")) {
        uint32_t match;

        if (strlen(p) < 1)
            continue;

        if ((r = strchr(p, '#')) != NULL) {
            *r++  = 0;
            count = strtol(r, NULL, 16);
        } else
            count = 1;

        if (strcmp(p, "**") == 0)
            match = NX_SIG_FLAG_WILD;
        else if (sscanf(p, "%X|%X|%X", &b1, &b2, &b3) == 3)
            match = NX_SIG_FLAG_OR | ((b1 & 0xFF) << 16) | ((b2 & 0xFF) << 8) | (b3 & 0xFF);
        else if (sscanf(p, "%X|%X", &b1, &b2) == 2)
            match = NX_SIG_FLAG_OR | ((b1 & 0xFF) << 8) | (b2 & 0xFF);
        else
            match = strtol(p, NULL, 16);


        for (i = 0; i < count; i++) {
            skip = false;

            for (j = 0; j < state->nxss_count; j++) {
                if (state->nxss_nodes[j].nxsn_match == match) {
                    skip  = true;
                    state = state->nxss_nodes[j].nxsn_next;
                    break;
                }
            }

            if (!skip) {
                struct nx_sig_search_node_s node;

                node.nxsn_match = match;
                node.nxsn_next  = nx_safe_calloc(1, sizeof(*state));

                state->nxss_nodes = nx_safe_realloc(state->nxss_nodes, (state->nxss_count + 1) * sizeof(node));
                memcpy(&(state->nxss_nodes[state->nxss_count++]), &node, sizeof(node));

                state = node.nxsn_next;
            }
        }
    }

    if (state->nxss_id || state->nxss_count > 0)
        return -1;

    state->nxss_id = id;

    nx_safe_free(copy);

    return -1;
}


/*! Run an existing search engine
 *
 */
int nx_sig_search_run(nx_sig_search_t *eng)
{
    int i, j, k, matches = 0;
    size_t cursors = 1;
    unsigned char *p = (unsigned char *)NX_NWN_SEARCH_START;
    struct nx_sig_search_cursor_s **cur = NULL;


    cur    = nx_safe_calloc(1, sizeof(*cur));
    cur[0] = nx_safe_calloc(1, sizeof(**cur));

    cur[0]->nxsc_state  = eng->nxse_root;
    cur[0]->nxsc_active = 1;


    while (p < (unsigned char *)NX_NWN_SEARCH_END) {
        for (i = 0; i < cursors; i++) {
            if (cur[i] == NULL || cur[i]->nxsc_active <= 0)
                continue;

            for (j = 0; j < cur[i]->nxsc_state->nxss_count; j++) {
                uint32_t match = cur[i]->nxsc_state->nxss_nodes[j].nxsn_match;

                if (nx_sig_search_match(*p, match)) {
                    struct nx_sig_search_state_s *next = cur[i]->nxsc_state->nxss_nodes[j].nxsn_next;

                    if (next->nxss_id) {
                        matches++;
                        eng->nxse_callback(next->nxss_id, p - cur[i]->nxsc_depth);
                    } else {
                        for (k = 1; k < cursors; k++) {
                            if (cur[k]->nxsc_active < 0)
                                break;
                        }

                        if (k == cursors) {
                            cur    = nx_safe_realloc(cur, sizeof(*cur) * ++cursors);
                            cur[k] = nx_safe_calloc(1, sizeof(**cur));
                        }

                        cur[k]->nxsc_state  = next;
                        cur[k]->nxsc_depth  = cur[i]->nxsc_depth + 1;
                        cur[k]->nxsc_active = 0;
                    }
                }
            }

            if (i > 0)
                cur[i]->nxsc_active = -1;
        }

        for (i = 1; i < cursors; i++) {
            if (cur[i]->nxsc_active == 0)
                cur[i]->nxsc_active = 1;
        }

        p++;
    }

    for (i = 0; i < cursors; i++) {
        if (cur[i] != NULL)
            nx_safe_free(cur[i]);
    }

    nx_safe_free(cur);

    return matches;
}


/*! Search for a single signature
 *
 */
void *nx_sig_search(const char *sig)
{
    return NULL;
}

/* vim: set sw=4: */

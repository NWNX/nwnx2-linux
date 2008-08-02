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

#ifndef _NX_NWN_STRUCT_CEXOARRAYLIST_H_
#define _NX_NWN_STRUCT_CEXOARRAYLIST_H_


/* XXX: delindex does not work right; do not use it or delvalue */
#define NX_NWN_CEXOARRAYLIST(N, T) \
    struct CExoArrayList_ ## N ## _s {                                                         \
        T          *data;                                                                      \
        int32_t     len;                                                                       \
        int32_t     alloc;                                                                     \
    };                                                                                         \
    static inline int CExoArrayList_ ## N ## _add (CExoArrayList_ ## N *list, T val) {         \
        if (list->len == list->alloc) {                                                        \
            T *re;                                                                             \
            if ((re = (T *)realloc(list->data, sizeof(T) * (list->alloc + 1))) == NULL)        \
                return -1;                                                                     \
            list->data = re;                                                                   \
            list->alloc++;                                                                     \
        }                                                                                      \
        list->data[list->len++] = val;                                                         \
        return list->len;                                                                      \
    }                                                                                          \
    static inline int CExoArrayList_ ## N ## _delindex (CExoArrayList_ ## N *list, int idx) {  \
        if (idx < 0 || idx >= list->len)                                                       \
            return -1;                                                                         \
        if (idx < list->len - 1)                                                               \
            memmove(&(list[idx]), &(list[idx + 1]), sizeof(T) * (list->len - (idx + 1)));      \
        return --(list->len);                                                                  \
    }                                                                                          \


#define NX_NWN_CEXOARRAYLIST_CONTAINS(N, T) \
    NX_NWN_CEXOARRAYLIST(N, T)                                                                           \
    static inline int CExoArrayList_ ## N ## _contains (const CExoArrayList_ ## N *list, const T val) {  \
        int i;                                                                                           \
        for (i = 0; i < list->len; i++) {                                                                \
            if (list->data[i] == val)                                                                    \
                return i + 1;                                                                            \
        }                                                                                                \
        return 0;                                                                                        \
    }                                                                                                    \
    static inline int CExoArrayList_ ## N ## _delvalue (CExoArrayList_ ## N *list, const T val) {        \
        int i;                                                                                           \
        for (i = 0; i < list->len; i++) {                                                                \
            if (list->data[i] == val)                                                                    \
                CExoArrayList_ ## N ## _delindex(list, i--);                                             \
        }                                                                                                \
        return list->len;                                                                                \
    }                                                                                                    \
    static inline T CExoArrayList_ ## N ## _get (CExoArrayList_ ## N *list, int idx) {                   \
        if (idx < 0 || idx >= list->len)                                                                 \
            return (T)0;                                                                                 \
        return list->data[idx];                                                                          \
    }

NX_NWN_CEXOARRAYLIST_CONTAINS(int8,   int8_t)
NX_NWN_CEXOARRAYLIST_CONTAINS(int32,  int32_t)
NX_NWN_CEXOARRAYLIST_CONTAINS(uint8,  uint8_t)
NX_NWN_CEXOARRAYLIST_CONTAINS(uint16, uint16_t)
NX_NWN_CEXOARRAYLIST_CONTAINS(uint32, uint32_t)
NX_NWN_CEXOARRAYLIST_CONTAINS(uint64, uint64_t)
NX_NWN_CEXOARRAYLIST_CONTAINS(float,  float)
NX_NWN_CEXOARRAYLIST_CONTAINS(ptr,    void *)


#endif /* _NX_NWN_STRUCT_CEXOARRAYLIST_H_ */

/* vim: set sw=4: */

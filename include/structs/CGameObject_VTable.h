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

#ifndef _NX_NWN_STRUCT_CGAMEOBJECT_VTABLE_
#define _NX_NWN_STRUCT_CGAMEOBJECT_VTABLE_

struct CGameObject_VTable_s {
    void                       *unknown_1;                                                              /* 00 */
    void                       *unknown_2;                                                              /* 04 */
    void                       *destructor;                                                             /* 08 */
    int                       (*SetId)(void *, uint32_t);                                               /* 0C */
    int                       (*ResetUpdateTimes)(void *, uint32_t, uint32_t);                          /* 10 */
    void *                    (*AsNWCObject)(void *);                                                   /* 14 */
    CNWSObject *              (*AsNWSObject)(void *);                                                   /* 18 */
    void *                    (*AsNWCDoor)(void *);                                                     /* 1C */
    CNWSDoor *                (*AsNWSDoor)(void *);                                                     /* 20 */
    void *                    (*AsNWCModule)(void *);                                                   /* 24 */
    CNWSModule *              (*AsNWSModule)(void *);                                                   /* 28 */
    void *                    (*AsNWCArea)(void *);                                                     /* 2C */
    CNWSArea *                (*AsNWSArea)(void *);                                                     /* 30 */
    void *                    (*AsNWCCreature)(void *);                                                 /* 34 */
    CNWSCreature *            (*AsNWSCreature)(void *);                                                 /* 38 */
    void *                    (*AsNWCItem)(void *);                                                     /* 3C */
    CNWSItem *                (*AsNWSItem)(void *);                                                     /* 40 */
    void *                    (*AsNWCTrigger)(void *);                                                  /* 44 */
    CNWSTrigger *             (*AsNWSTrigger)(void *);                                                  /* 48 */
    void *                    (*AsNWCProjectile)(void *);                                               /* 4C */
    void *                    (*AsNWSPlayerTURD)(void *);                                               /* 50 */
    CNWSPlaceable *           (*AsNWSPlaceable)(void *);                                                /* 54 */
    void *                    (*AsNWCPlaceable)(void *);                                                /* 58 */
    CNWSAreaOfEffectObject *  (*AsNWSAreaOfEffectObject)(void *);                                       /* 5C */
    void *                    (*AsNWCAreaOfEffectObject)(void *);                                       /* 60 */
    CNWSWaypoint *            (*AsNWSWaypoint)(void *);                                                 /* 64 */
    CNWSEncounter *           (*AsNWSEncounter)(void *);                                                /* 68 */
    void *                    (*AsNWCStore)(void *);                                                    /* 6C */
    CNWSStore *               (*AsNWSStore)(void *);                                                    /* 70 */
    CNWSSoundObject *         (*AsNWSSoundObject)(void *);                                              /* 74 */
    void *                    (*AsNWCSoundObject)(void *);                                              /* 78 */
    int                       (*AIUpdate)(void *);                                                      /* 7C */
    int                       (*ClearAction)(void *, void *, int);                                      /* 80 */
    int                       (*EventHandler)(void *, uint32_t, uint32_t, void *, uint32_t, uint32_t);  /* 84 */
    int                       (*SetAnimation)(void *, int);                                             /* 88 */
    int                       (*GetDialogResref)(void *);                                               /* 8C */
    int                       (*GetDialogInterruptable)(void *);                                        /* 90 */
    int                       (*GetGender)(void *);                                                     /* 94 */
    int                       (*GetFirstName)(void *);                                                  /* 98 */
    int                       (*GetLastName)(void *);                                                   /* 9C */
    int                       (*GetMaxHitPoints)(void *, int);                                          /* A0 */
    int16_t                   (*GetCurrentHitPoints)(void *, int);                                      /* A4 */
    int                       (*DoDamage)(void *, int);                                                 /* A8 */
    int                       (*DoDamageReduction)(void *, void *, int, uint8_t, int, int);             /* AC */
    int                       (*DoDamageResistance)(void *, void *, int, uint16_t, int, int, int);      /* B0 */
    int                       (*GetMaximumDamageResistanceVsDamageFlag)(void *, uint16_t, int *);       /* B4 */
    int                       (*DoDamageImmunity)(void *, void *, int, uint16_t, int, int);             /* B8 */
    int                       (*GetDamageImmunity)(void *, uint8_t);                                    /* BC */
    int                       (*GetDamageImmunityByFlags)(void *, uint16_t);                            /* C0 */
};

#endif /* _NX_NWN_STRUCT_CGAMEOBJECT_VTABLE_ */

/* vim: set sw=4: */

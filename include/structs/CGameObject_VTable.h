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
    void                       *unknown_1;
    void                       *unknown_2;
    void                       *destructor;
    int                       (*SetId)(void *, uint32_t);
    int                       (*ResetUpdateTimes)(void *, uint32_t, uint32_t);
    void *                    (*AsNWCObject)(void *);
    CNWSObject *              (*AsNWSObject)(void *);
    void *                    (*AsNWCDoor)(void *);
    CNWSDoor *                (*AsNWSDoor)(void *);
    void *                    (*AsNWCModule)(void *);
    CNWSModule *              (*AsNWSModule)(void *);
    void *                    (*AsNWCArea)(void *);
    CNWSArea *                (*AsNWSArea)(void *);
    void *                    (*AsNWCCreature)(void *);
    CNWSCreature *            (*AsNWSCreature)(void *);
    void *                    (*AsNWCItem)(void *);
    CNWSItem *                (*AsNWSItem)(void *);
    void *                    (*AsNWCTrigger)(void *);
    CNWSTrigger *             (*AsNWSTrigger)(void *);
    void *                    (*AsNWCProjectile)(void *);
    void *                    (*AsNWSPlayerTURD)(void *);
    CNWSPlaceable *           (*AsNWSPlaceable)(void *);
    void *                    (*AsNWCPlaceable)(void *);
    CNWSAreaOfEffectObject *  (*AsNWSAreaOfEffectObject)(void *);
    void *                    (*AsNWCAreaOfEffectObject)(void *);
    CNWSWaypoint *            (*AsNWSWaypoint)(void *);
    CNWSEncounter *           (*AsNWSEncounter)(void *);
    void *                    (*AsNWCStore)(void *);
    CNWSStore *               (*AsNWSStore)(void *);
    CNWSSoundObject *         (*AsNWSSoundObject)(void *);
    void *                    (*AsNWCSoundObject)(void *);
    void                       *unknown_3;
};

#endif /* _NX_NWN_STRUCT_CGAMEOBJECT_VTABLE_ */

/* vim: set sw=4: */

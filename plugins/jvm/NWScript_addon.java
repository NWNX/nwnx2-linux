    /**
     * Get all currently online players.
    **/
    public native static synchronized NWObject[] getPCs() throws NWNotInContextException;

    /**
     * Get all effects on the given NWObject.
    **/
    public native static synchronized NWEffect[] getEffects(NWObject oWithEffects) throws NWNotInContextException;

    /**
     * Get all itemproperties on the given NWObject.
    **/
    public native static synchronized NWItemProperty[] getItemProperties(NWObject oItem) throws NWNotInContextException;

    /**
     * Get all items in the given NWObjects inventory.
    **/
    public native static synchronized NWObject[] getItemsInInventory(NWObject oWithInventory) throws NWNotInContextException;

    /**
     * Get all objects in the given area.
    **/
    public native static synchronized NWObject[] getObjectsInArea(NWObject oArea) throws NWNotInContextException;

    /**
     * Get all objects in the given shape.
     * @param nShape SHAPE_*
     * @param fSize
	 * -> If nShape == SHAPE_SPHERE, this is the radius of the sphere
     * -> If nShape == SHAPE_SPELLCYLINDER, this is the length of the cylinder
     * Spell Cylinder's always have a radius of 1.5m.
     * -> If nShape == SHAPE_CONE, this is the widest radius of the cone
     * -> If nShape == SHAPE_SPELLCONE, this is the length of the cone in the
     * direction of lTarget. Spell cones are always 60 degrees with the origin
     * at OBJECT_SELF.
     * -> If nShape == SHAPE_CUBE, this is half the length of one of the sides of
     * the cube
     * @param lTarget This is the centre of the effect, usually GetSpellTargetLocation(),
     * or the end of a cylinder or cone.
     * @param bLineOfSight This controls whether to do a line-of-sight check on the
     * object returned. Line of sight check is done from origin to target object
     * at a height 1m above the ground
     * (This can be used to ensure that spell effects do not go through walls.)
     * @param nObjectFilter This allows you to filter out undesired object types, using
     * bitwise "or".
     * For example, to return only creatures and doors, the value for this
     * parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
     * @param vOrigin This is only used for cylinders and cones, and specifies the
     * origin of the effect(normally the spell-caster's position).
    **/
    public native static synchronized NWObject[] getObjectsInShape(int nShapeType, float fSize, NWLocation lTarget, boolean bLineOfSight, int nObjectFilter, NWVector vOrigin) throws NWNotInContextException;

    /**
     * Returns all members of the given objects faction.
    */
    public native static synchronized NWObject[] getFactionMembers(NWObject oMemberOf, boolean bPCOnly) throws NWNotInContextException;

    /**
     * Get all objects within within oPersistentObject.
     * @param oPersistentObject
     * @param nResidentObjectType OBJECT_TYPE_*
     * @param nPersistentZone PERSISTENT_ZONE_ACTIVE. [This could also take the value
     * PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
    **/
    public native static synchronized NWObject[] getObjectsInPersistentObject(NWObject oPersistentObject, int nResidentObjectType, int nPersistentZone) throws NWNotInContextException;

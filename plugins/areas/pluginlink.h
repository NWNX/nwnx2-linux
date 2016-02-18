#pragma once

/**
 * Service: SERVICE_AREAS_LOAD_AREA
 * Param: AreasLoadAreaService
 *
 * Loads a new area from resref. You need to have resref ready in ResMan.
 *
 * Will return the object id of the newly instanced area,
 * or OBJECT_INVALID on errors.
 */
#define SERVICE_AREAS_LOAD_AREA "Areas/LoadArea()"

struct AreasLoadAreaService {
	const char *resref;

	nwobjid areaId;
};

/**
 * Service: SERVICE_AREAS_DESTROY_AREA
 * Param: AreasDestroyAreaService
 *
 * Unloads an area from the running module.
 */
#define SERVICE_AREAS_DESTROY_AREA "Areas/DestroyArea()"

struct AreasDestroyAreaService {
	const nwobjid areaId;

    bool success;
};

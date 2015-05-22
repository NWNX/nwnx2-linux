#include "NWNXFuncs.h"


void Func_SetIsCreatureDisarmable(CGameObject *oObject, char *sValue)
{
    CNWSCreature *oCreature;

    if (
        oObject == NULL                                               ||
        (oCreature = oObject->vtable->AsNWSCreature(oObject)) == NULL ||
        oCreature->cre_stats == NULL
    ) {
        snprintf(sValue, strlen(sValue), "0");
        return;
    }

    int bValue = atoi(sValue) != 0;

    oCreature->cre_is_disarmable = bValue;

    snprintf(sValue, strlen(sValue), "1");
}

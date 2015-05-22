#include "NWNXFuncs.h"


void Func_SetCorpseDecayTime(CGameObject *oObject, char *sValue)
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

    int nValue = atoi(sValue);

    if (nValue <= 0) {
        snprintf(sValue, strlen(sValue), "0");
        return;
    }

    oCreature->cre_decaytime = nValue;

    snprintf(sValue, strlen(sValue), "1");
}

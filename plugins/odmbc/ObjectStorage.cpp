/***************************************************************************
    odbc plugin for NWNX  - hooks implementation
    copyright (c) 2006 dumbo (dumbo@nm.ru)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#include <sys/types.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <math.h>

#include <limits.h>		/* for PAGESIZE */
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

#include "ObjectStorage.h"
#include "NWNXodbc.h"
#include "CExoString.h"

extern CNWNXODBC odbc;

dword ppServThis = 0x0832F1F4;
dword pServThis = 0; //g_pAppManager

//ServerExoApp
CNWSObject *(*CServerExoApp__GetGameObject)(void *pServerExoApp, dword nObjID) = (CNWSObject * (*)(void *, dword)) 0x080B1D98;
CNWSArea *(*CServerExoApp__GetAreaByGameObjectID)(void *pServerExoApp, dword nObjID) = (CNWSArea * (*)(void *, dword)) 0x080B1E10;

//Vector
Vector *(*normalize)(Vector const &dest, Vector const &src) = (Vector * (*)(Vector const &, Vector const &)) 0x0826B144;

//CResGFF
void (*CResGFF__CResGFF)(CResGFF *pGFF) = (void (*)(CResGFF*)) 0x082B8370;
void (*CResGFF___CResGFF)(CResGFF *pGFF, int n) = (void (*)(CResGFF*, int)) 0x082B85E0;
int (*CResGFF__CreateGFFFile)(CResGFF *pGFF, CResStruct *pResStruct, CExoString const &sType, CExoString const &sVersion) = (int (*)(CResGFF*, CResStruct*, const CExoString&, const CExoString&)) 0x082BAAC4;
int (*CResGFF__WriteGFFToPointer)(CResGFF *pGFF, void **ppBuffer, int&nLength) = (int (*)(CResGFF*, void**, int&)) 0x082BAE78;
int (*CResGFF__GetDataFromPointer)(CResGFF *pGFF, void *pData, int nSize) = (int (*)(CResGFF*, void*, int)) 0x082B961C;
void (*CResGFF__GetGFFFileInfo)(CResGFF *pGFF, CExoString *sType, CExoString *sVersion) = (void (*)(CResGFF*, CExoString*, CExoString*)) 0x082BB70C;
int (*CResGFF__GetTopLevelStruct)(CResGFF *pGFF, CResStruct *pResStruct) = (int (*)(CResGFF*, CResStruct*)) 0x082BBA5C;

//CNWSPlaceable
void (*CNWSPlaceable__CNWSPlaceable)(CNWSPlaceable *pObject, dword a1) = (void (*)(CNWSPlaceable*, dword)) 0x081DB8F0;
int (*CNWSPlaceable__SavePlaceable)(CNWSPlaceable *pObject, CResGFF *pGFF, CResStruct *pResStruct) = (int (*)(CNWSPlaceable*, CResGFF *, CResStruct*)) 0x081DE414;
int (*CNWSPlaceable__LoadPlaceable)(CNWSPlaceable *pObject, CResGFF *pGFF, CResStruct *pResStruct, CExoString *sTag) = (int (*)(CNWSPlaceable*, CResGFF*, CResStruct*, CExoString*)) 0x081DC150;
int (*CNWSPlaceable__AddToArea)(CNWSPlaceable *pObject, CNWSArea *pArea, float x, float y, float z, int a) = (int (*)(CNWSPlaceable*, CNWSArea*, float, float, float, int)) 0x081DF174;
void (*CNWSPlaceable__SetOrientation)(CNWSPlaceable *pObject, Vector v) = (void (*)(CNWSPlaceable*, Vector)) 0x081DF084;

//CNWSStore
void (*CNWSStore__CNWSStore)(CNWSStore *pObject, dword a1) = (void (*)(CNWSStore*, dword)) 0x08083C0C;
int (*CNWSStore__SaveStore)(CNWSStore *pObject, CResGFF *pGFF, CResStruct *pResStruct) = (int (*)(CNWSStore*, CResGFF *, CResStruct*)) 0x08084DB8;
int (*CNWSStore__LoadStore)(CNWSStore *pObject, CResGFF *pGFF, CResStruct *pResStruct, CExoString *sTag) = (int (*)(CNWSStore*, CResGFF*, CResStruct*, CExoString*)) 0x08084230;
int (*CNWSStore__AddToArea)(CNWSStore *pObject, CNWSArea *pArea, float x, float y, float z, int a) = (int (*)(CNWSStore*, CNWSArea*, float, float, float, int)) 0x08085B0C;

//CNWSTrigger
void (*CNWSTrigger__CNWSTrigger)(CNWSTrigger *pObject, dword a1) = (void (*)(CNWSTrigger*, dword)) 0x081EE180;
int (*CNWSTrigger__SaveTrigger)(CNWSTrigger *pObject, CResGFF *pGFF, CResStruct *pResStruct) = (int (*)(CNWSTrigger*, CResGFF *, CResStruct*)) 0x081F1610;
int (*CNWSTrigger__LoadTrigger)(CNWSTrigger *pObject, CResGFF *pGFF, CResStruct *pResStruct, CExoString *sTag) = (int (*)(CNWSTrigger*, CResGFF*, CResStruct*, CExoString*)) 0x081F0138;
int (*CNWSTrigger__AddToArea)(CNWSTrigger *pObject, CNWSArea *pArea, float x, float y, float z, int a) = (int (*)(CNWSTrigger*, CNWSArea*, float, float, float, int)) 0x081EE668;

//CNWSObject
void (*CNWSObject__SaveVarTable)(CNWSObject *pObject, CResGFF *pGFF, CResStruct *pResStruct) = (void (*)(CNWSObject*, CResGFF*, CResStruct*)) 0x081D4BD8;
void (*CNWSObject__LoadVarTable)(CNWSObject *pObject, CResGFF *pGFF, CResStruct *pResStruct) = (void (*)(CNWSObject*, CResGFF*, CResStruct*)) 0x081D4BC0;
void (*CNWSObject__SetPosition)(CNWSObject *pObject, Vector vPos, int bSkipArea) = (void (*)(CNWSObject*, Vector, int)) 0x081D4E30;
void (*CNWSObject__SetOrientation)(CNWSObject *pObject, Vector v) = (void (*)(CNWSObject*, Vector)) 0x081D4E10;

void InitConstants();

Vector FacingToOrientation(float fFacing)
{
    Vector v, vRes;
    v.X = cos(fFacing * M_PI / 180);
    v.Y = sin(fFacing * M_PI / 180);
    v.Z = 0;
    normalize(vRes, v);
    return vRes;
}

void ApplyInventoryLoadPatch(unsigned long pAddr, bool bEnabled)
{
    unsigned char * pCode = (unsigned char *)pAddr;
    d_enable_write((unsigned long)pCode);
    if (bEnabled) {
        pCode[1] = 0x88;
    } else {
        pCode[1] = 0x80;
    }
}

char *SaveObject(dword nObjectID, int &nSize)
{
    if (!pServThis)
        InitConstants();
    int (*SaveObjectInternal)(CNWSObject * pObject, CResGFF * pGFF, CResStruct * pResStruct);
    const char * sGFFType = NULL;
    odbc.Log(4, "SaveObject: %x\n", nObjectID);
    CNWSObject *pObject = CServerExoApp__GetGameObject((void *)pServThis, nObjectID);
    odbc.Log(4, "pObject: %08lx\n", pObject);
    if (pObject) {
        if (pObject->ObjectType == 9) { //placeable
            //return SavePlaceable((CNWSPlaceable *)pObject, nSize);
            SaveObjectInternal = (int (*)(CNWSObject*, CResGFF *, CResStruct*)) CNWSPlaceable__SavePlaceable;
            sGFFType = "UTP ";
        } else if (pObject->ObjectType == 0xE) { //store
            SaveObjectInternal = (int (*)(CNWSObject*, CResGFF *, CResStruct*)) CNWSStore__SaveStore;
            sGFFType = "UTM ";
        } else if (pObject->ObjectType == 0x7) { //trigger
            SaveObjectInternal = (int (*)(CNWSObject*, CResGFF *, CResStruct*)) CNWSTrigger__SaveTrigger;
            sGFFType = "UTT ";
        } else {
            nSize = 0;
            return NULL;
        }
        CExoString sVersion("V2.0");
        CExoString sType(sGFFType);
        CResGFF *pGFF = new CResGFF;
        CResStruct *pResStruct = new CResStruct;
        odbc.Log(4, "Created structures\n");
        CResGFF__CResGFF(pGFF);
        odbc.Log(4, "CResGFF__CResGFF - done\n");
        if (CResGFF__CreateGFFFile(pGFF, pResStruct, sType, sVersion)) {
            odbc.Log(4, "CResGFF__CreateGFFFile - done\n");
            if (SaveObjectInternal(pObject, pGFF, pResStruct)) {
                odbc.Log(4, "CNWSPlaceable__SavePlaceable - done\n");
                //TODO: Save object state / Load var table
                CNWSObject__SaveVarTable(pObject, pGFF, pResStruct);
                void *pData;
                int nDataSize;
                if (CResGFF__WriteGFFToPointer(pGFF, &pData, nDataSize)) {
                    odbc.Log(4, "CResGFF__WriteGFFToPointer - done\n");
                    odbc.Log(4, "Length: %d, data: %s\n", nDataSize, pData);
                    //free(pData);

                    if (pGFF)
                        CResGFF___CResGFF(pGFF, 3);
                    delete pResStruct;

                    nSize = nDataSize;
                    return (char *)pData;
                }
            }
        }
        if (pGFF)
            CResGFF___CResGFF(pGFF, 3);
        delete pResStruct;
        nSize = 0;
        return NULL;
    } else {
        nSize = 0;
        return NULL;
    }
}

/*char *SavePlaceable(CNWSPlaceable *pObject, int &pnSize)
{
	CExoString sVersion("V2.0");
	CExoString sType("UTP ");
	CResGFF *pGFF = new CResGFF;
	CResStruct *pResStruct = new CResStruct;
	odbc.Log(4, "Created structures\n");
	CResGFF__CResGFF(pGFF);
	odbc.Log(4, "CResGFF__CResGFF - done\n");
	if(CResGFF__CreateGFFFile(pGFF, pResStruct, sType, sVersion)){
		odbc.Log(4, "CResGFF__CreateGFFFile - done\n");
		if(CNWSPlaceable__SavePlaceable(pObject, pGFF, pResStruct)){
			odbc.Log(4, "CNWSPlaceable__SavePlaceable - done\n");
			//TODO: Save object state / Load var table
			//CNWSObject__SaveVarTable(pObject, pGFF, pResStruct);
			void *pData;
			int nDataSize;
			if(CResGFF__WriteGFFToPointer(pGFF, &pData, nDataSize)){
				odbc.Log(4, "CResGFF__WriteGFFToPointer - done\n");
				odbc.Log(4, "Length: %d, data: %s\n", nDataSize, pData);
				//free(pData);

				if(pGFF)
					CResGFF___CResGFF(pGFF, 3);
				delete pResStruct;

				pnSize = nDataSize;
				return (char *)pData;
			}
		}
	}
	if(pGFF)
		CResGFF___CResGFF(pGFF, 3);
	delete pResStruct;
	pnSize = 0;
	return NULL;
}

char *SaveStore(CNWSStore *pObject, int &pnSize)
{
	CExoString sVersion("V2.0");
	CExoString sType("UTM ");
	CResGFF *pGFF = new CResGFF;
	CResStruct *pResStruct = new CResStruct;
	odbc.Log(4, "Created structures\n");
	CResGFF__CResGFF(pGFF);
	odbc.Log(4, "CResGFF__CResGFF - done\n");
	if(CResGFF__CreateGFFFile(pGFF, pResStruct, sType, sVersion)){
		odbc.Log(4, "CResGFF__CreateGFFFile - done\n");
		if(CNWSStore__SaveStore(pObject, pGFF, pResStruct)){
			odbc.Log(4, "CNWSStore__SaveStore - done\n");
			//TODO: Save object state / Load var table
			//CNWSObject__SaveVarTable(pObject, pGFF, pResStruct);
			void *pData;
			int nDataSize;
			if(CResGFF__WriteGFFToPointer(pGFF, &pData, nDataSize)){
				odbc.Log(4, "CResGFF__WriteGFFToPointer - done\n");
				odbc.Log(4, "Length: %d, data: %s\n", nDataSize, pData);
				//free(pData);

				if(pGFF)
					CResGFF___CResGFF(pGFF, 3);
				delete pResStruct;

				pnSize = nDataSize;
				return (char *)pData;
			}
		}
	}
	if(pGFF)
		CResGFF___CResGFF(pGFF, 3);
	delete pResStruct;
	pnSize = 0;
	return NULL;
}*/

dword LoadObject(const char *pData, int nSize, Location lLocation)
{
    CExoString sVersion, sType;
    if (!pServThis)
        InitConstants();
    if (lLocation.AreaID == 0x7F000000 || !CServerExoApp__GetAreaByGameObjectID((void *)pServThis, lLocation.AreaID))
        return 0x7F000000;

    CResGFF *pGFF = new CResGFF;
    CResStruct *pResStruct = new CResStruct;
    odbc.Log(4, "Created structures\n");
    CResGFF__CResGFF(pGFF);
    odbc.Log(4, "CResGFF__CResGFF - done\n");
    if (CResGFF__GetDataFromPointer(pGFF, (void *) pData, nSize)) {
        odbc.Log(4, "CResGFF__GetDataFromPointer - done\n");
        CResGFF__GetGFFFileInfo(pGFF, &sType, &sVersion);
        if (CResGFF__GetTopLevelStruct(pGFF, pResStruct)) {
            odbc.Log(4, "CResGFF__GetTopLevelStruct - done\n");
            odbc.Log(4, "sType = %s\n", sType.Text);
        }
    }
    //new
    //constructor
    //Load*
    //LoadVarTable
    //SetPosition
    //SetOrientation
    //AddToArea
    if (sType == "UTP ") {
        odbc.Log(4, "Loading placeable...\n");
        CNWSPlaceable *pObject = new CNWSPlaceable;
        CNWSPlaceable__CNWSPlaceable(pObject, 0x7F000000);
        odbc.Log(4, "CNWSPlaceable__CNWSPlaceable - done\n");
        ApplyInventoryLoadPatch(0x081DD49D, true);
        CNWSPlaceable__LoadPlaceable(pObject, pGFF, pResStruct, NULL);
        ApplyInventoryLoadPatch(0x081DD49D, false);
        CNWSObject__LoadVarTable((CNWSObject *)pObject, pGFF, pResStruct);
        odbc.Log(4, "CNWSPlaceable__LoadPlaceable - done\n");
        CNWSArea *pArea = CServerExoApp__GetAreaByGameObjectID((void *)pServThis, lLocation.AreaID);
        odbc.Log(4, "pArea = %08lx\n", pArea);
        if (pArea) {
            odbc.Log(4, "AreaID = %08lx, area type = %d\n", lLocation.AreaID, pArea->GameObject.ObjectID);
            CNWSObject__SetPosition((CNWSObject *)pObject, lLocation.vect, 0);
            odbc.Log(4, "CNWSObject__SetPosition - done\n");
            CNWSPlaceable__SetOrientation(pObject, FacingToOrientation(lLocation.Facing));
            CNWSPlaceable__AddToArea(pObject, pArea, lLocation.vect.X, lLocation.vect.Y, lLocation.vect.Z, 1);
            odbc.Log(4, "CNWSPlaceable__AddToArea - done\n");
        }
        if (pGFF)
            CResGFF___CResGFF(pGFF, 3);
        delete pResStruct;
        return pObject->Object.ObjectID;
    } else if (sType == "UTM ") {
        odbc.Log(4, "Loading store...\n");
        CNWSStore *pObject = new CNWSStore;
        CNWSStore__CNWSStore(pObject, 0x7F000000);
        odbc.Log(4, "CNWSStore__CNWSStore - done\n");
        ApplyInventoryLoadPatch(0x080847FE, true);
        CNWSStore__LoadStore(pObject, pGFF, pResStruct, NULL);
        ApplyInventoryLoadPatch(0x080847FE, false);
        CNWSObject__LoadVarTable((CNWSObject *)pObject, pGFF, pResStruct);
        odbc.Log(4, "CNWSStore__LoadStore - done\n");
        CNWSArea *pArea = CServerExoApp__GetAreaByGameObjectID((void *)pServThis, lLocation.AreaID);
        odbc.Log(4, "pArea = %08lx\n", pArea);
        if (pArea) {
            odbc.Log(4, "AreaID = %08lx, area type = %d\n", lLocation.AreaID, pArea->GameObject.ObjectID);
            CNWSObject__SetPosition((CNWSObject *)pObject, lLocation.vect, 0);
            odbc.Log(4, "CNWSObject__SetPosition - done\n");
            CNWSObject__SetOrientation((CNWSObject *)pObject, FacingToOrientation(lLocation.Facing));
            CNWSStore__AddToArea(pObject, pArea, lLocation.vect.X, lLocation.vect.Y, lLocation.vect.Z, 1);
            odbc.Log(4, "CNWSStore__AddToArea - done\n");
        }
        if (pGFF)
            CResGFF___CResGFF(pGFF, 3);
        delete pResStruct;
        return pObject->Object.ObjectID;
    } else if (sType == "UTT ") {
        odbc.Log(4, "Loading store...\n");
        CNWSTrigger *pObject = new CNWSTrigger;
        CNWSTrigger__CNWSTrigger(pObject, 0x7F000000);
        odbc.Log(4, "CNWSTrigger__CNWSTrigger - done\n");
        CNWSTrigger__LoadTrigger(pObject, pGFF, pResStruct, NULL);
        CNWSObject__LoadVarTable((CNWSObject *)pObject, pGFF, pResStruct);
        odbc.Log(4, "CNWSTrigger__LoadTrigger - done\n");
        CNWSArea *pArea = CServerExoApp__GetAreaByGameObjectID((void *)pServThis, lLocation.AreaID);
        odbc.Log(4, "pArea = %08lx\n", pArea);
        if (pArea) {
            odbc.Log(4, "AreaID = %08lx, area type = %d\n", lLocation.AreaID, pArea->GameObject.ObjectID);
            CNWSObject__SetPosition((CNWSObject *)pObject, lLocation.vect, 0);
            odbc.Log(4, "CNWSObject__SetPosition - done\n");
            CNWSObject__SetOrientation((CNWSObject *)pObject, FacingToOrientation(lLocation.Facing));
            CNWSTrigger__AddToArea(pObject, pArea, lLocation.vect.X, lLocation.vect.Y, lLocation.vect.Z, 1);
            odbc.Log(4, "CNWSTrigger__AddToArea - done\n");
        }
        if (pGFF)
            CResGFF___CResGFF(pGFF, 3);
        delete pResStruct;
        return pObject->Object.ObjectID;
    }
    if (pGFF)
        CResGFF___CResGFF(pGFF, 3);
    delete pResStruct;
    return 0x7F000000;
}

void HookObjectStorage()
{

}

void InitConstants()
{
    CServerExoApp__GetGameObject = (CNWSObject * (*)(void *, dword)) 0x080B1D98;
    CServerExoApp__GetAreaByGameObjectID = (CNWSArea * (*)(void *, dword)) 0x080B1E10;

    normalize = (Vector * (*)(Vector const &, Vector const &)) 0x0826B144;

    //CResGFF
    CResGFF__CResGFF = (void (*)(CResGFF*)) 0x082B8370;
    CResGFF___CResGFF = (void (*)(CResGFF*, int)) 0x082B85E0;
    CResGFF__CreateGFFFile = (int (*)(CResGFF*, CResStruct*, const CExoString&, const CExoString&)) 0x082BAAC4;
    CResGFF__WriteGFFToPointer = (int (*)(CResGFF*, void**, int&)) 0x082BAE78;
    CResGFF__GetDataFromPointer = (int (*)(CResGFF*, void*, int)) 0x082B961C;
    CResGFF__GetGFFFileInfo = (void (*)(CResGFF*, CExoString*, CExoString*)) 0x082BB70C;
    CResGFF__GetTopLevelStruct = (int (*)(CResGFF*, CResStruct*)) 0x082BBA5C;



    //CNWSPlaceable
    CNWSPlaceable__CNWSPlaceable = (void (*)(CNWSPlaceable*, dword)) 0x081DB8F0;
    CNWSPlaceable__SavePlaceable = (int (*)(CNWSPlaceable*, CResGFF *, CResStruct*)) 0x081DE414;
    CNWSPlaceable__LoadPlaceable = (int (*)(CNWSPlaceable*, CResGFF*, CResStruct*, CExoString*)) 0x081DC150;
    CNWSPlaceable__AddToArea = (int (*)(CNWSPlaceable*, CNWSArea*, float, float, float, int)) 0x081DF174;
    CNWSPlaceable__SetOrientation = (void (*)(CNWSPlaceable*, Vector)) 0x081DF084;

    //CNWSStore
    CNWSStore__CNWSStore = (void (*)(CNWSStore*, dword)) 0x08083C0C;
    CNWSStore__SaveStore = (int (*)(CNWSStore*, CResGFF *, CResStruct*)) 0x08084DB8;
    CNWSStore__LoadStore = (int (*)(CNWSStore*, CResGFF*, CResStruct*, CExoString*)) 0x08084230;
    CNWSStore__AddToArea = (int (*)(CNWSStore*, CNWSArea*, float, float, float, int)) 0x08085B0C;

    //CNWSTrigger
    CNWSTrigger__CNWSTrigger = (void (*)(CNWSTrigger*, dword)) 0x081EE180;
    CNWSTrigger__SaveTrigger = (int (*)(CNWSTrigger*, CResGFF *, CResStruct*)) 0x081F1610;
    CNWSTrigger__LoadTrigger = (int (*)(CNWSTrigger*, CResGFF*, CResStruct*, CExoString*)) 0x081F0138;
    CNWSTrigger__AddToArea = (int (*)(CNWSTrigger*, CNWSArea*, float, float, float, int)) 0x081EE668;

    //CNWSObject
    CNWSObject__SaveVarTable = (void (*)(CNWSObject*, CResGFF*, CResStruct*)) 0x081D4BD8;
    CNWSObject__LoadVarTable = (void (*)(CNWSObject*, CResGFF*, CResStruct*)) 0x081D4BC0;
    CNWSObject__SetPosition = (void (*)(CNWSObject*, Vector, int)) 0x081D4E30;
    CNWSObject__SetOrientation = (void (*)(CNWSObject*, Vector)) 0x081D4E10;


    pServThis = *((*(dword**)ppServThis) + 1);
}



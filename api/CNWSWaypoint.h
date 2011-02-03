#ifndef _CNWSWAYPOINT_H_
#define _CNWSWAYPOINT_H_
#include "nwndef.h"
#include "CResRef.h"
#include "CExoLocString.h"

class CNWSWaypoint
{
public:
	int AIUpdate();
	int AddToArea(CNWSArea *, float, float, float, int);
	int AsNWSWaypoint();
	int EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
	int GetFirstName();
	int GetIsMapNote();
	int GetMapNoteEnabled();
	int GetMapNoteString();
	int LoadFromTemplate(CResRef, CExoString *);
	int LoadWaypoint(CResGFF *, CResStruct *, CExoString *);
	int RemoveFromArea();
	int SaveWaypoint(CResGFF *, CResStruct *);
	int SetIsMapNote(int);
	int SetMapNoteEnabled(int);
	int SetMapNoteString(CExoLocString);
	~CNWSWaypoint();
	CNWSWaypoint(unsigned long);

};
#endif

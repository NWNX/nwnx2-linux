#ifndef _CNWSWAYPOINT_H_
#define _CNWSWAYPOINT_H_
#include "nwndef.h"
#include "CNWSArea.h"
#include "CExoLocString.h"
#include "CResRef.h"
#include "CExoString.h"
#include "CResGFF.h"
#include "nwnstructs.h"

class CNWSWaypoint
{
public:
	void AIUpdate();
	void AddToArea(CNWSArea *, float, float, float, int);
	CNWSWaypoint * AsNWSWaypoint();
	void EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
	CExoLocString & GetFirstName();
	int GetIsMapNote();
	int GetMapNoteEnabled();
	CExoLocString & GetMapNoteString();
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

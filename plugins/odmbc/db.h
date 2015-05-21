/***************************************************************************
    CDB.h: interface for the CDB base class.
    Copyright (C) 2004 Jeroen Broekhuizen (nwnx@jengine.nl)
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

#if !defined _DB_H_
#define _DB_H_

//#include "../nwnxbase.h"

#define MAXSQL 1024
#define MAXRESULT 1024*1024

typedef unsigned char BOOL;
typedef unsigned char BYTE;
typedef unsigned int  uint;
typedef unsigned long ulong;
typedef unsigned char uchar;

class CDB
{
public:
    CDB() { }

    virtual BOOL Connect() = 0;
    virtual void Disconnect() = 0;

    virtual BOOL Execute(const uchar* query) = 0;
    virtual char * Fetch(char * buffer, unsigned int buffersize) = 0;
    virtual BOOL WriteScorcoData(char* SQL, BYTE* pData, int Length) = 0;
    virtual BYTE * ReadScorcoData(const char * SQL, const char * param, BOOL * pSqlError, int * size) = 0;

    virtual const char* GetErrorMessage() = 0;

protected:
    BYTE pReturn[MAXRESULT]; // static buffer for data return

};

#endif

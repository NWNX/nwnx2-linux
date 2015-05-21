/***************************************************************************
    NWNXSystem.cpp - Implementation of the CNWNXSystem class.
    Copyright (C) 2010 Ilerien Phoenix (ilerienphoenix@gmail.com)

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

#include "NWNXSystem.h"

extern CNWNXSystem sys;

const ssize_t RESULT_SIZE = sizeof(long);
const char* FILE_DEV_URANDOM = "/dev/urandom";

void Func_TrueRandom(CGameObject *ob, char *value)
{
    long* nMax = (long*)malloc(RESULT_SIZE);

    long nResult = -1;
    FILE* oFile;

    sscanf(value, "%ld ", nMax);

    if (*nMax > 0 && (oFile = fopen(FILE_DEV_URANDOM, "r")) != NULL) {
        long* nRand = (long*)malloc(RESULT_SIZE);

        if (fread(nRand, RESULT_SIZE, 1, oFile) == 1)
            nResult = abs(*nRand % *nMax);

        fclose(oFile);
        free(nRand);
    }

    free(nMax);

    snprintf(value, strlen(value), "%ld", nResult);
}

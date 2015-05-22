#include <stdlib.h>
#include <string.h>
#include "C2DA.h"

int C2DA::GetColumnID(char *sColumn)
{
    unsigned int nColLength = strlen(sColumn);
    CExoString *pCols = this->ColumnNames;
    for (int i = 0; i < this->ColumnCount; i++) {
        if (strncmp(pCols[i].Text, sColumn, nColLength) == 0) {
            return i;
        }
    }
    return -1;
}

int C2DA::GetRowID(unsigned int nRow)
{
    CExoString *pRowLabels = this->IDList;
    for (int i = 0; i < this->RowCount; i++) {
        if (atoi(pRowLabels[i].Text) == nRow) {
            return i;
        }
    }
    return -1;
}



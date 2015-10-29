#include <iostream>
#include "duplicate.h"
#include "check.h"


namespace Sudoku {


inline const char *okStr(bool ok)
{ return ok ? "is valid" : "is invalid"; }


inline void printDivisionCheckInfo(const char *div, int index, bool ok)
{ std::cout << div << ' ' << index << ' ' << okStr(ok) << std::endl; }


inline void printGeneralCheckInfo(const char *div, bool ok)
{ std::cout << div << ' ' << okStr(ok) << std::endl; }


void printResult(bool ok)
{ std::cout << "matrix " << okStr(ok) << std::endl; }


bool checkRows(int *matrix)
{
    bool result = true;
    
    int *row = matrix;
    for (int i = 0; i < DIM; ++i, row += DIM) {
        bool ok = !rowHasDuplicates(row);
        printDivisionCheckInfo("row", i + 1, ok);
        result &= ok;
    }
    
    return result;
}


bool checkColumns(int *matrix)
{
    bool result = true;
    
    int *column = matrix;
    for (int i = 0; i < DIM; ++i, ++column) {
        bool ok = !columnHasDuplicates(column);
        printDivisionCheckInfo("column", i + 1, ok);
        result &= ok;
    }
    
    return result;
}


bool checkSectors(int *matrix)
{
    bool result = true;
    int shiftSequence[DIM] = { 3, 3, 21, 3, 3, 21, 3, 3, 0 };
    
    int *sector = matrix;
    for (int i = 0; i < DIM; sector += shiftSequence[i++]) {
        bool ok = !sectorHasDuplicates(sector);
        printDivisionCheckInfo("sector", i + 1, ok);
        result &= ok;
    }
    
    return result;
}


} // namespace Sudoku

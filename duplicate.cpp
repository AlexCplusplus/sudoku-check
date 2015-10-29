#include "check.h"
#include "duplicate.h"


namespace Sudoku {


namespace {
const unsigned int PACK_MASK = 0x1FF;    // 2e9 - 1
}


bool rowHasDuplicates(int *row)
{
    unsigned int pack = 0;

    for (int i = 0; i < DIM; ++i, ++row) {
        pack |= (1 << (*row - 1));
    }

    return pack ^ PACK_MASK;
}


bool columnHasDuplicates(int *column)
{
    unsigned int pack = 0;

    for (int i = 0; i < DIM; ++i, column += DIM) {
        pack |= (1 << (*column - 1));
    }

    return pack ^ PACK_MASK;
}


bool sectorHasDuplicates(int *sector)
{
    unsigned int pack = 0;
    int shiftSequence[DIM] = { 1, 1, 7, 1, 1, 7, 1, 1, 0 };

    for (int i = 0; i < DIM; sector += shiftSequence[i++]) {
        pack |= (1 << (*sector - 1));
    }

    return pack ^ PACK_MASK;
}


} // namespace Sudoku

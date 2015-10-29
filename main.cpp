#include "input.h"
#include "check.h"


int main()
{
    int sudoku[Sudoku::DIM][Sudoku::DIM] = { 0 };
    if (int input = Sudoku::read(sudoku[0]))
        return input;

    bool rows = Sudoku::checkRows(sudoku[0]);
    bool columns = Sudoku::checkColumns(sudoku[0]);
    bool sectors = Sudoku::checkSectors(sudoku[0]);
    Sudoku::printResult(rows && columns && sectors);

    return 0;
}

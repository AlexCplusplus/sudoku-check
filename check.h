#ifndef _check_h_
#define _check_h_


namespace Sudoku {


const int DIM = 9;


void printResult(bool ok);

bool checkRows(int *matrix);
bool checkColumns(int *matrix);
bool checkSectors(int *matrix);


} // namespace Sudoku


#endif // _check_h_

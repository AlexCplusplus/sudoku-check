#ifndef _input_h_
#define _input_h_


namespace Sudoku {


const int FILE_OPEN_ERR = 1;
const int FILE_PREMATURE_END_ERR = 2;
const int INPUT_ERROR = 3;
const int INVALID_DATA_ERR = 4;


int read(int *matrix);


} // namespace Sudoku


#endif // _input_h_

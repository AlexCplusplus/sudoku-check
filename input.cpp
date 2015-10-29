#include <iostream>
#include <fstream>
#include "check.h"

#include "input.h"


namespace Sudoku {


int read(int *matrix)
{
    std::fstream input;
    input.open("sudoku_input.txt", std::ios_base::in);
    if (!input.is_open()) {
        std::cout << "Can not open file." << std::endl;
        return FILE_OPEN_ERR;
    }

    int *end = matrix + (DIM * DIM);
    for (int *m = matrix; m != end; ++m) {
        if (input.eof()) {
            std::cout << "Input file contains insufficient data." << std::endl;
            return FILE_PREMATURE_END_ERR;
        }

        input >> *m;
        if (input.fail()) {
            std::cout << "An error occurred during an input operation." << std::endl;
            return INPUT_ERROR;
        }

        if (!(1 <= *m && *m <= 9)) {
            std::cout << "Values in the range 1...9 are allowed only." << std::endl;
            return INVALID_DATA_ERR;
        }
    }

    return 0;
}


} // namespace Sudoku

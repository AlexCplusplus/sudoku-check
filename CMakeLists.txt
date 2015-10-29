cmake_minimum_required (VERSION 2.6)

set (APP sudoku-check)
project (${APP})

message ("Project: ${PROJECT_NAME}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

set (HEADERS check.h
             duplicate.h
             input.h)
set (SOURCES check.cpp
             duplicate.cpp
             input.cpp
             main.cpp)
set (RESOURCES sudoku_input.txt)

add_executable (${APP} ${SOURCES})
configure_file (sudoku_input.txt
                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sudoku_input.txt COPYONLY)

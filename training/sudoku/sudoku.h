#include <stdio.h>
#include <stdlib.h>

#ifndef SUDOKU_LIBRARY_H
#define SUDOKU_LIBRARY_h

void createRandomMatrix(int matrix[9][9]);

void lineVerification(int matrix[9][9], int valid_result);

void columnVerification(int matrix[9][9], int valid_result);

void blockVerification(int matrix[9][9], int valid_result);

#endif

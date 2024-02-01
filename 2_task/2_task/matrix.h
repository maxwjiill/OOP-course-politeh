#ifndef MATRIX_H
#define MATRIX_H

int** FillMatrix(int& rows, int& cols);
void PrintMatrix(int** matrix, int rows, int cols);
void DeleteMatrix(int** matrix, int rows);
int** SubtractMatrix(int** matrix1, int** matrix2, int rows, int cols);

#endif

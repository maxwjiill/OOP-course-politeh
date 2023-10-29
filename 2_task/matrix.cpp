#include "matrix.h"
#include <iostream>

int** FillMatrix(int& rows, int& cols) {
    int** matrix = new int*[rows];

    std::cout << "Matrix elements:" << std::endl;
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    return matrix;
}

void PrintMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void DeleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int** SubtractMatrix(int** matrix1, int** matrix2, int rows, int cols) {
    int** result = new int*[rows];

    for (int i = 0; i < rows; i++) {
        result[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}
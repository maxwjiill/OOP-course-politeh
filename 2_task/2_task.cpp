//g++ 2_task.cpp matrix.cpp -o 2_task
//Metelkin -> int V = int('M')%8 -> 5 variant "Matrix subtraction"

#include <iostream>
#include "matrix.h"
using namespace std;


int main()
{
    int rows1 = 0, cols1 = 0;
    int rows2 = 0, cols2 = 0;
    int** matrix1 = nullptr;
    int** matrix2 = nullptr;

    string function_choice;

    while (true)
    {
        cout << "\n\nMENU\n\nSelect option:\n"
            "\t\'i1\' - fill first matrix\n"
            "\t\'i2\' - fill second matrix\n"
            "\t\'s\' - show matrix\n"
            "\t\'o\' - operation matrix (5 variant - subtract matrix)\n"
            "\t\'e\' - for exit from program\n"
            "Your choice: ";
        cin >> function_choice;

        switch (function_choice[0])
        {
        
        case 'i':
            if (function_choice == "i1") {

                if (matrix1 != nullptr) {
                    DeleteMatrix(matrix1, rows1);
                    matrix1 = nullptr;
                    std::cout << "first matrix has been deleted." << std::endl;
                }

                std::cout << "rows first matrix: ";
                std::cin >> rows1;

                std::cout << "cols first matrix: ";
                std::cin >> cols1;

                matrix1 = FillMatrix(rows1, cols1);
            }
            else if (function_choice == "i2") {
                if (matrix2 != nullptr) {
                    DeleteMatrix(matrix2, rows2);
                    matrix2 = nullptr;
                    std::cout << "second matrix has been deleted." << std::endl;
                }
                
                std::cout << "rows second matrix: ";
                std::cin >> rows2;

                std::cout << "cols second matrix: ";
                std::cin >> cols2;

                matrix2 = FillMatrix(rows2, cols2);
            }
            break;
        
        case 's':
            if (matrix1 != nullptr) {
                std::cout << "first matrix: " << std::endl;
                PrintMatrix(matrix1, rows1, cols1);
            } else {
                std::cout << "first matrix is null" << std::endl;
            }

            if (matrix2 != nullptr) {
                std::cout << "second matrix: " << std::endl;
                PrintMatrix(matrix2, rows2, cols2);
            } else {
                std::cout << "second matrix is null" << std::endl;
            }
            break;
        
        case 'o':
            if (rows1 == rows2 && cols1 == cols2) {
                int** resultSubtractMatrix = SubtractMatrix(matrix1, matrix2, rows1, cols1);
                std::cout << "result subtract: " << std::endl;
                PrintMatrix(resultSubtractMatrix, rows1, cols1);
                DeleteMatrix(resultSubtractMatrix, rows1);
            } else {
                std::cout << "matrices have different sizes and cannot be subtracted" << std::endl;
            }
            break;
        
        case 'e':
            if (matrix1 != nullptr) {
                DeleteMatrix(matrix1, rows1);
                matrix1 = nullptr;
            }
            if (matrix2 != nullptr) {
                DeleteMatrix(matrix2, rows2);
                matrix2 = nullptr;
            }
            cout << "Exiting the program" << endl;
            return 0;
        
        default:
            cout << "\nInvalid character: " << function_choice << endl;
            break;

        }
    }

    // clear anyway
    if (matrix1 != nullptr) {
        DeleteMatrix(matrix1, rows1);
        matrix1 = nullptr;
    }
    if (matrix2 != nullptr) {
        DeleteMatrix(matrix2, rows2);
        matrix2 = nullptr;
    }

    return 0;
}
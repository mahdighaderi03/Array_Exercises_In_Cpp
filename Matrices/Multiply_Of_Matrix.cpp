#include <iostream>
using namespace std;

const int max_size = 10;

void Read_matrix(int matrix_1[][max_size], int matrix_2[][max_size], int row_1, int column_1, int row_2, int column_2);
void Show_matrix(int matrix[][max_size], int row, int column);
void Multiply_Of_Matrix(int matrix_1[][max_size], int matrix_2[][max_size], int result[][max_size], int row_1, int column_1, int row_2, int column_2);

int main() {
    cout << "Enter first matrix information: " << endl;
    int row_1, column_1;
    cout << "Enter number of rows: ";
    cin >> row_1;
    cout << "Enter number of columns: ";
    cin >> column_1;

    int matrix_1[max_size][max_size];

    cout << "Enter second matrix information: " << endl;
    int row_2, column_2;
    cout << "Enter number of rows: ";
    cin >> row_2;
    cout << "Enter number of columns: ";
    cin >> column_2;

    int matrix_2[max_size][max_size];

    Read_matrix(matrix_1, matrix_2, row_1, column_1, row_2, column_2);
    Show_matrix(matrix_1, row_1, column_1);
    Show_matrix(matrix_2, row_2, column_2);

    if (column_1 == row_2) {
        int result[max_size][max_size];
        Multiply_Of_Matrix(matrix_1, matrix_2, result, row_1, column_1, row_2, column_2);
    }
    else {
        cout << "Error! "<< endl;
    }

    return 0;
}

void Read_matrix(int matrix_1[][max_size], int matrix_2[][max_size], int row_1, int column_1, int row_2, int column_2) {
    cout << "Matrix 1: " << endl;
    for (int i = 0; i < row_1; i++) {
        for (int j = 0; j < column_1; j++) {
            cout << "Enter your number: ";
            cin >> matrix_1[i][j];
        }
    }

    cout << "Matrix 2: " << endl;
    for (int i = 0; i < row_2; i++) {
        for (int j = 0; j < column_2; j++) {
            cout << "Enter your number: ";
            cin >> matrix_2[i][j];
        }
    }
}

void Show_matrix(int matrix[][max_size], int row, int column) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Multiply_Of_Matrix(int matrix_1[][max_size], int matrix_2[][max_size], int result[][max_size], int row_1, int column_1, int row_2, int column_2) {
    for (int i = 0; i < row_1; i++) {
        for (int j = 0; j < column_2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < column_1; k++) {
                result[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }

    cout << "Result after multiplication:" << endl;
    Show_matrix(result, row_1, column_2);
}

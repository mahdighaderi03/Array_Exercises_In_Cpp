#include<iostream>
using namespace std;

const int max_size = 10;

void Read_matrix(int a[][3], int non_zero);
void Show_matrix(int a[][3], int non_zero);
void Transfer_matrix(int a[][3], int transposed[][max_size], int non_zero);

int main() {
    int non_zero;
    cout << "Enter number of non-zero values: ";
    cin >> non_zero;

    int a[non_zero][3];
    int transposed[max_size][non_zero];

    Read_matrix(a, non_zero);
    Show_matrix(a, non_zero);
    Transfer_matrix(a, transposed, non_zero);

    return 0;
}

void Read_matrix(int a[][3], int non_zero) {
    for (int i = 0; i < non_zero; i++) {
        int row, column, value;
        cout << "Enter row number: ";
        cin >> row;
        a[i][0] = row;
        cout << "Enter column number: ";
        cin >> column;
        a[i][1] = column;
        cout << "Enter non-zero value: ";
        cin >> value;
        a[i][2] = value;
    }
}

void Show_matrix(int a[][3], int non_zero) {
    for (int i = 0; i < non_zero; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void Transfer_matrix(int a[][3], int transposed[][max_size], int non_zero) {
    for (int i = 0; i < max_size; ++i) {
        for (int j = 0; j < non_zero; ++j) {
            transposed[i][j] = 0;
        }
    }

    for (int i = 0; i < non_zero; ++i) {
        int row = a[i][0];
        int col = a[i][1];
        int value = a[i][2];
        transposed[col][i] = value;
    }

    cout << "Transposed matrix:" << endl;
    for (int i = 0; i < max_size; ++i) {
        for (int j = 0; j < non_zero; ++j) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
}

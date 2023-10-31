#include <iostream>
using namespace std;

const int max_size = 10;

void Read_matrix(int a[][max_size], int n, int m);
void Show_matrix(int a[][max_size], int n, int m);
void Sparse_style(int a[][max_size], int n, int m);

int main() {
    int n, m;
    cout << "Enter size of matrix: " << endl;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    int a[max_size][max_size];
    Read_matrix(a, n, m);
    Show_matrix(a, n, m);
    Sparse_style(a, n, m);

    return 0;
}

void Read_matrix(int a[][max_size], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter a number: ";
            cin >> a[i][j];
        }
    }
}

void Show_matrix(int a[][max_size], int n, int m) {
    cout << "Matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void Sparse_style(int a[][max_size], int n, int m) {
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0)
                zeros++;
        }
    }

    int sparseMatrix[zeros + 1][3];
    sparseMatrix[0][0] = n;
    sparseMatrix[0][1] = m;
    sparseMatrix[0][2] = zeros;
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0) {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = a[i][j];
                k++;
            }
        }
    }

    cout << "Sparse Matrix: " << endl;
    for (int i = 0; i < zeros + 1; i++) {
        cout << sparseMatrix[i][0] << " ";
        cout << sparseMatrix[i][1] << " ";
        cout << sparseMatrix[i][2] << endl;
    }
}

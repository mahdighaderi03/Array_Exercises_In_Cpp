#include<iostream>
using namespace std;

void Read_first_matrix(int matrix_1[][3], int coulumns_1, int rows_1, int non_zero_1);
void Show_first_matrix(int matrix_1[][3], int coulumns_1, int rows_1, int non_zero_1);
void Read_second_matrix(int matrix_2[][3], int coulumns_2, int rows_2, int non_zero_2);
void Show_second_matrix(int matrix_2[][3], int coulumns_2, int rows_2, int non_zero_2);
void Sum_of_sparse_matrix(int matrix_1[][3], int matrix_2[][3], int result[][3], int non_zero_1, int non_zero_2);

int main(){
    cout << "Enter first matrix information: " << endl;
    int coulumns_1, rows_1, non_zero_1;
    cout << "Enter number of coulumns: ";
    cin >> coulumns_1;
    cout << "Enter number if rows: ";
    cin >> rows_1;
    cout << "Enter number of non zero values: ";
    cin >> non_zero_1;

    int matrix_1[non_zero_1 + 1][3];

    cout << "Enter second matrix information: " << endl;
    int coulumns_2, rows_2, non_zero_2;
    cout << "Enter number of coulumns: ";
    cin >> coulumns_2;
    cout << "Enter number if rows: ";
    cin >> rows_2;
    cout << "Enter number of non zero values: ";
    cin >> non_zero_2;

    int matrix_2[non_zero_2 + 1][3];

    Read_first_matrix(matrix_1, coulumns_1, rows_1, non_zero_1);
    Show_first_matrix(matrix_1, coulumns_1, rows_1, non_zero_1);
    Read_second_matrix(matrix_2, coulumns_2, rows_2, non_zero_2);
    Show_second_matrix(matrix_2, coulumns_2, rows_2, non_zero_2);

    int result[non_zero_1 + non_zero_2 + 1][3];


}

void Read_first_matrix(int matrix_1[][3], int coulumns_1, int rows_1, int non_zero_1){
    matrix_1[0][0] = rows_1;
    matrix_1[0][1] = coulumns_1;
    matrix_1[0][2] = non_zero_1;
    for (int i = 1; i < non_zero_1 + 1; i++){
        int row, coulumn, value;
        cout << "Enter rows number: ";
        cin >> row;
        matrix_1[i][0] = row;
        cout << "Enter coulumn numner: ";
        cin >> coulumn;
        matrix_1[i][1] = coulumn;
        cout << "Enter non zero value: ";
        cin >> value;
        matrix_1[i][2] = value;
    }

}

void Read_second_matrix(int matrix_2[][3], int coulumns_2, int rows_2, int non_zero_2){
    matrix_2[0][0] = rows_2;
    matrix_2[0][1] = coulumns_2;
    matrix_2[0][2] = non_zero_2;
    for (int i = 1; i < non_zero_2 + 1; i++){
        int row, coulumn, value;
        cout << "Enter rows number: ";
        cin >> row;
        matrix_2[i][0] = row;
        cout << "Enter coulumn numner: ";
        cin >> coulumn;
        matrix_2[i][1] = coulumn;
        cout << "Enter non zero value: ";
        cin >> value;
        matrix_2[i][2] = value;
    }
}

void Show_first_matrix(int matrix_1[][3], int coulumns_1, int rows_1, int non_zero_1) {
	for (int i = 0; i < non_zero_1 + 1; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix_1[i][j] << " ";
		}
		cout << endl;
	}
}

void Show_second_matrix(int matrix_2[][3], int coulumns_2, int rows_2, int non_zero_2){
    for (int i = 0; i < non_zero_2 + 1; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix_2[i][j] << " ";
		}
		cout << endl;
	}
}

void Sum_of_sparse_matrix(int matrix_1[][3], int matrix_2[][3], int result[][3], int non_zero_1, int non_zero_2){
     int i = 1, j = 1, k = 1;
    while (i <= non_zero_1 && j <= non_zero_2) {
        if (matrix_1[i][0] < matrix_2[j][0] || (matrix_1[i][0] == matrix_2[j][0] && matrix_1[i][1] < matrix_2[j][1])) {
            result[k][0] = matrix_1[i][0];
            result[k][1] = matrix_1[i][1];
            result[k][2] = matrix_1[i][2];
            i++;
        }
        else if (matrix_1[i][0] > matrix_2[j][0] || (matrix_1[i][0] == matrix_2[j][0] && matrix_1[i][1] > matrix_2[j][1])) {
            result[k][0] = matrix_2[j][0];
            result[k][1] = matrix_2[j][1];
            result[k][2] = matrix_2[j][2];
            j++;
        }
        else {
            result[k][0] = matrix_1[i][0];
            result[k][1] = matrix_1[i][1];
            result[k][2] = matrix_1[i][2] + matrix_2[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i <= non_zero_1){
        result[k][0] = matrix_1[i][0];
        result[k][1] = matrix_1[i][1];
        result[k][2] = matrix_1[i][2];
        i++;
        k++;
    }

    while (j <= non_zero_2){
        result[k][0] = matrix_2[j][0];
        result[k][1] = matrix_2[j][1];
        result[k][2] = matrix_2[j][2];
        j++;
        k++;
    }
}

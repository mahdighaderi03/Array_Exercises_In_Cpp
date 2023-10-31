#include<iostream>
using namespace std;

void Read_Polynomial(int polynomial_1[][2], int polynomial_2[][2], int n, int m);
void Show_Polynomial(int polynomial_1[][2], int polynomial_2[][2], int n, int m);
void Sum_Polynomial(int polynomial_1[][2], int polynomial_2[][2], int n, int m);

int main(){
    int n , m;
    cout << "Please Enter the number of The first sentence: ";
    cin >> n;
    cout << "Please Enter the number of The second sentence: ";
    cin >> m;

    int polynomial_1[n][2];
    int polynomial_2[m][2];

    Read_Polynomial(polynomial_1, polynomial_2, n, m);
    Show_Polynomial(polynomial_1, polynomial_2, n, m);
    Sum_Polynomial(polynomial_1, polynomial_2, n, m);

    return 0;
}

void Read_Polynomial(int polynomial_1[][2], int polynomial_2[][2], int n, int m){

    cout << "Enter the first polynomial information: " << endl;
    for (int i = 0; i < n; i++){
        cout << "Enter " << i + 1 << "th Coefficient of first sentence: ";
        cin >> polynomial_1[i][0];
        cout << "Enter " << i + 1 << "th power of first sentence: ";
        cin >> polynomial_1[i][1];
    }

    cout << "Enter the second polynomial information: " << endl;
    for (int i = 0; i < m; i++){
        cout << "Enter " << i + 1 << "th Coefficient the second sentence: ";
        cin >> polynomial_2[i][0];
        cout << "Enter " << i + 1 << "th power the second sentence: ";
        cin >> polynomial_2[i][1];
    }
}

void Show_Polynomial(int polynomial_1[][2], int polynomial_2[][2], int n, int m){
    cout << "Polynomial 1: " << endl;
    for(int i = 0; i < n; i++){
        cout << polynomial_1[i][0] << "x^" << polynomial_1[i][1];
        if(i < n - 1) {
            cout << " + ";
        }
    }
    cout << endl;

    cout << "Polynomial 2: " << endl;
    for(int i = 0; i < m; i++){
        cout << polynomial_2[i][0] << "x^" << polynomial_2[i][1];
        if(i < m - 1) {
            cout << " + ";
        }
    }
    cout << endl;
}

void Sum_Polynomial(int polynomial_1[][2], int polynomial_2[][2], int n, int m) {
    int max_sum = n + m;
    int result[max_sum];

    for (int i = 0; i < max_sum; i++){
        result[i] = 0;
    }

    for(int i = 0; i < n; i++){
        result[polynomial_1[i][1]] += polynomial_1[i][0];
    }

    for(int i = 0; i < m; i++){
        result[polynomial_2[i][1]] += polynomial_2[i][0];
    }

    cout << "Sum of the Polynomials: " << endl;
    bool firstTerm = true;
    for (int i = max_sum - 1; i >= 0; --i){
        if (result[i] != 0) {
            if (!firstTerm) {
                cout << "+";
            }
            cout << result[i];
            if (i > 0){
                cout << "x^" << i;
            }
            firstTerm = false;
        }
    }
    cout << endl;
}


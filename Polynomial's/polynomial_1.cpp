#include <iostream>
using namespace std;

void Read_Polynomials(int a[], int b[], int n, int m);
void Show_Polynomials(int a[], int b[], int n, int m);
void Sum_Polynomials(int a[], int b[], int n, int m);

int main() {
    int n, m;
    cout << "Please Enter the number of The first sentence: ";
    cin >> n;
    cout << "Please Enter the number of The seconde sentence: ";
    cin >> m;

    int* a = new int[n];
    int* b = new int[m];

    Read_Polynomials(a, b, n, m);
    Show_Polynomials(a, b, n, m);
    Sum_Polynomials(a, b, n, m);


    delete[] a;
    delete[] b;

    return 0;
}

void Read_Polynomials(int a[], int b[], int n, int m) {
    for (int i = 0; i < n; i++) {
        cout << "Enter " << i + 1 << "th Coefficient of first sentence: ";
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cout << "Enter " << i + 1 << "th Coefficient of seconde sentence: ";
        cin >> b[i];
    }
}

void Show_Polynomials(int a[], int b[], int n, int m){
    cout << "The first sentence: " << endl;
    for (int i = 0 ; i < n ; i++)
    {
        cout << a[i] << "x^" << i;
        cout << "+";
    }
    cout << endl;
    cout << "The seconde sentence: " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << "x^" << i;
        cout << "+";
    }
    cout << endl;
}

void Sum_Polynomials(int a[], int b[], int n, int m) {
    int maxSize = n + m;
    int* result = new int[maxSize];

    for (int i = 0; i < n; i++) {
        result[i] += a[i];
    }
    for (int i = 0; i < m; i++) {
        result[i] += b[i];
    }

    cout << "Sum of the polynomials: " << endl;
    for (int i = 0; i < maxSize; i++) {
        if (result[i] != 0){
            cout << result[i] << "x^" << i;
            cout << "+";
        }

    }
    cout << endl;

    delete[] result;
}


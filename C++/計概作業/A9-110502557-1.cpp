/**
 *  Assignment 09
 *  Name: 游宗穎
 *  Student Number: 110502557
 *  Course: 2021-CE1003-B
*/

#include <bits/stdc++.h>
using namespace std;

int x_m, x_n, y_m, y_n;
int arr_x[5][5], arr_y[5][5];
int ArrMulti(int, int);

int main() {
    cout << "Size of matrix A: "; cin >> x_m >> x_n;
    cout << "Size of matrix B: "; cin >> y_m >> y_n;
    if (x_n != y_m) {
        cout << "Can't be multiplied\n";
        return 0;
    }
    cout << "Matrix A:\n";
    for (int i = 0; i < x_m; i ++)
        for (int j = 0; j < x_n; j ++)
            cin >> arr_x[i][j];
    cout << "Matrix B:\n";
    for (int i = 0; i < y_m; i ++)
        for (int j = 0; j < y_n; j ++)
            cin >> arr_y[i][j];
    cout << "Multiplication:\n";
    for (int i = 0; i < x_m; i ++) {
        for (int j = 0; j < y_n; j ++) {
            cout << ArrMulti(i, j) << ' ';
        }
        cout << '\n';
    }
    return 0;
}

int ArrMulti(int m, int n) {
    int sum = 0;
    for (int i = 0; i < x_n; i ++)
        sum += arr_x[m][i] * arr_y[i][n];
    return sum;
}

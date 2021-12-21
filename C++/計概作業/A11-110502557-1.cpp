/**
 *  Assignment 11
 *  Name: 游宗穎
 *  Student Number: 110502557
 *  Course: 2021-CE1003-B
*/

#include <bits/stdc++.h>
using namespace std;

string Solve(int n) {
    int arr[10000];
    int max_size = n * n;
    for (int i = 0; i < max_size; i ++) {
        cin >> arr[i];
    }
    for (int i = 0; i < max_size / 2 + 1; i ++) {
        if (arr[i] != arr[max_size - i - 1])
            return "Non-Symmetric!";
    }
    return "Symmetric!";
}

int main() {
    int n;
    while (true) {
        cout << "Input size: ";
        cin >> n;
        if (n == -1) break;
        cout << Solve(n) << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void solve(int n, char A, char B, char C) {
    if (n == 1) {
        cout << A << " " << C << "\n";
    }
    else {
        solve(n - 1, A, C, B);
        solve(1, A, B, C);
        solve(n - 1, B, A, C);
    }
}

int main() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    solve(n, '1', '2', '3');
    return 0;
}
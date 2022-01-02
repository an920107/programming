#include <bits/stdc++.h>
using namespace std;

bool solve(int n) {
    int arr[200];
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    for (int i = n / 2; i < n; i ++) {
        if (arr[i] != arr[n - i - 1]) return false;
    }
    return true;
}

int main() {
    int m, n;
    int t; cin >> t;
    for (int i = 0; i < t; i ++) {
        cin >> m >> n;
        cout << (solve(m * n) ? "go forward\n" : "keep defending\n");
    }
    return 0;
}
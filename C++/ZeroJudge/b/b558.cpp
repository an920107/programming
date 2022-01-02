#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    while (cin >> n) {
        cout << n * (n - 1) / 2 + 1 << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long powi(long long x, long long y) {
    long long mul = 1;
    for (; y > 0; y --) {
        mul *= x;
    }
    return mul;
}

long long Solve(long long n) {
    long long digits = 0;
    while (n > 0) {
        digits ++;
        n -= 9 * powi(10, digits - 1) * digits;
    }
    n += 9 * powi(10, digits - 1) * digits;
    long long shift = (n - 1) / digits;
    long long d = (n - 1) % digits;
    string str = to_string(powi(10, digits - 1) + shift);
    return str[d] - 48;
}

int main() {
    int n;
    long long loc;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> loc;
        cout << Solve(loc) << "\n";
    }
    return 0;
}
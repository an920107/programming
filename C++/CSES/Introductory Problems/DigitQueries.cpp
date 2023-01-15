#include <bits/stdc++.h>
using namespace std;

#define llong long long

llong powi(llong x, llong y) {
    llong mul = 1;
    while (y --)
        mul *= x;
    return mul;
}

llong solve(llong n) {
    llong digits = 0;
    while (n > 0) {
        digits ++;
        n -= 9 * powi(10, digits - 1) * digits;
    }
    n += 9 * powi(10, digits - 1) * digits;
    const llong shift = (n - 1) / digits;
    const llong digitsIndex = (n - 1) % digits;
    const string str = to_string(powi(10, digits - 1) + shift);
    return str[digitsIndex] - 48;
}

int main() {
    int n;
    llong loc;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> loc;
        cout << solve(loc) << "\n";
    }
    return 0;
}
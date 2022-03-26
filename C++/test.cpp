#include <bits/stdc++.h>
using namespace std;

int min(int a, int b, int c, int d) {
    int arr[4] {a, b, c, d};
    sort(arr, arr + 4);
    return arr[0];
}

void bcd(int &a, int &b, int &c, int &d) {
    int div;
    int _a(a), _b(b), _c(c), _d(d);
    while (_a != 0 && _b != 0 && _c != 0 && _d != 0) {
        div = min(a, b, c, d);
        if (_a != div) _a %= div;
        if (_b != div) _b %= div;
        if (_c != div) _c %= div;
        if (_d != div) _d %= div;
    }
    cout << div << "\n";
    a /= div;
    b /= div;
    c /= div;
    d /= div;
}

int main() {
    int a(5), b(10), c(15), d(20);
    bcd(a, b, c, d);
    cout << a << b << c << d << "\n";
}
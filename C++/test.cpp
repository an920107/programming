#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    cout << gcd(16, 0);
    return 0;
}
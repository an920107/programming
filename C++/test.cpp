#include <bits/stdc++.h>
using namespace std;

int bcd(int m, int n) {
    if (m < n) return bcd(n, m);
    if (n == 0) return m;
    return bcd(n, m - n);
}

int main() {
    printf("%d", bcd(51, 17*16));
    return 0;
}
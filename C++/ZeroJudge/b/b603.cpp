#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;

    Point() {}
    explicit Point(int _x, int _y): x(_x), y(_y) {}
};

int bcd(int m, int n) {
    if (m < n) return bcd(n, m);
    if (n == 0) return m;
    return bcd(n, m - n);
}

Point fraction(int m, int n) {
    int div = bcd(m, n);
    return Point(m / div, n / div);
}

int main() {
    int x, y;
    int a, b, c, d;
    while (cin >> x >> y) {
        Point top {x, y};
        cin >> x >> y;
        Point side {x, y};
        Point frac = fraction(side.y - top.y, (side.x - top.x) * (side.x - top.x));
        a = frac.x;
        b = frac.y;
    }
    return 0;
}

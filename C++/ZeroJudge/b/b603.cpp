#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;

    Point() {}
    explicit Point(int _x, int _y): x(_x), y(_y) {}
};

int min(int a, int b, int c, int d) {
    int arr[4] {a, b, c, d};
    sort(arr, arr + 4);
    return arr[0];
}

void bcd(int &a, int &b, int &c, int &d) {
    int div;
    int _a(abs(a)), _b(abs(b)), _c(abs(c)), _d(abs(d));
    while (_a != 0 && _b != 0 && _c != 0 && _d != 0) {
        div = min(_a, _b, _c, _d);
        if (_a != div) _a %= div;
        if (_b != div) _b %= div;
        if (_c != div) _c %= div;
        if (_d != div) _d %= div;
    }
    a /= div;
    b /= div;
    c /= div;
    d /= div;
}

int main() {
    int x, y;
    int a, b, c, d, div;
    while (cin >> x >> y) {
        Point top {x, y};
        cin >> x >> y;
        Point side {x, y};
        a = (side.x - top.x) * (side.x - top.x);
        b = side.y - top.y;
        c = - 2 * b * top.x;
        d = b * top.x * top.x + a * top.y;
        bcd(a, b, c, d);
        printf("%dy = %dx^2 + %dx + %d\n", a, b, c, d);
    }
    return 0;
}

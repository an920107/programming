#include <bits/stdc++.h>
using namespace std;

typedef struct point {
    int x, y;
    point(int _x, int _y) : x(_x), y(_y) {}
    double slope(point &to) {
        return double(to.y - this->y) / (to.x - this->x);
    }
} Point;

auto pointCmp = [](Point &a, Point &b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
};

vector<Point> points;
double slopeL, slopeR;

int main() {
    int t, y, x, result = 0;
    cin >> t;
    cin >> y >> x;
    slopeL = double(y) / x;
    cin >> y >> x;
    slopeR = double(y) / x;
    while (t --) {
        cin >> x >> y;
        points.emplace_back(Point(x, y));
    }
    sort(points.begin(), points.end(), pointCmp);
    for (int i = 0; i < points.size() - 1; i ++) {
        
    }
    cout << result << '\n';
    return 0;
}
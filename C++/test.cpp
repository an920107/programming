#include <bits/stdc++.h>
using namespace std;

struct Point {
    int dimension;
    int *parameter;

    Point(int _dim): dimension(_dim) {
        parameter = (int*)malloc(dimension * sizeof(int));
    }
    
    int &operator[](int index) {
        return parameter[index];
    }

    friend ostream &operator<<(ostream &os, Point &p) {
        os << p[0];
        for (int i = 1; i < p.dimension; i ++)
            os << ' ' << p[i];
        return os;
    }

    inline void downgrade() {
        dimension --;
        parameter ++;
    }

    inline void upgrade() {
        dimension ++;
        parameter --;
    }

    void downgradeTo2D() {
        while (dimension > 2)
            downgrade();
    }
};

auto cmpReverse = [](Point &a, Point &b) {
    return a[0] > b[0];
};

vector<Point> points;

void solve2D() {
    sort(points.begin(), points.end(), cmpReverse);
    vector<int> toRemoveIndex;
    bool firstFlag = true;
    int maxSubParm = points[0][1];
    for (int i = 1, j = 1; i < points.size(); i = j) {
        if (points[j][0] != points[j - 1][0]) {
            if (points[j][1] > maxSubParm)
                maxSubParm = points[j][1];
            j ++;
            firstFlag = false;
        }
        else for (j = i; j < points.size() && points[j][0] == points[j - 1][0]; j ++)
            if (points[j][1] > maxSubParm)
                maxSubParm = points[j][1];
        for (int k = (firstFlag ? 0 : i); k < j; k ++)
            if (points[k][1] < maxSubParm)
                toRemoveIndex.emplace_back(k);
        firstFlag = false;
    }
    for (auto &index : toRemoveIndex)
        points.erase(points.begin() + index);
}

void solve() {
    int originalDim = points[0].dimension;
    for (int i = 0; i < points.size(); i ++)
        points[i].downgradeTo2D();
    solve2D();
    while (points[0].dimension < originalDim) {
        for (int i = 0; i < points.size(); i ++)
            points[i].upgrade();
        solve2D();
    }
}


#define DIMENSION 3

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i ++) {
        points.emplace_back(Point(DIMENSION));
        for (int j = 0; j < DIMENSION; j ++)
            cin >> points.back()[j];
    }

    solve();

    for (auto &p : points)
        cout << p << '\n';

    return 0;
}
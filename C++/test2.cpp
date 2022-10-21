#include <bits/stdc++.h>
using namespace std;

/** 
 * definition of struct point
 */

struct Point {
    int dimension;
    int *coordinate;

    Point(int _dimension): dimension(_dimension) {
        coordinate = (int*)malloc(dimension * sizeof(int));
    }

    bool dominate(Point &p) {
        bool result = true;
        for (int i = 0; result && i < dimension; i ++)
            result &= coordinate[i] >= p.coordinate[i];
        return result;
    }
};

auto pointCmp = [](Point &a, Point &b) {
    int dimension = a.dimension;
    for (int i = 0; i < dimension; i ++) {
        if (a.coordinate[i] != b.coordinate[i])
            return a.coordinate[i] < b.coordinate[i];
    }
    return a.coordinate[dimension - 1] < b.coordinate[dimension - 1];
};

auto pointReverseCmp = [](Point &b, Point &a) {
    int dimension = a.dimension;
    for (int i = 0; i < dimension; i ++) {
        if (a.coordinate[i] != b.coordinate[i])
            return a.coordinate[i] < b.coordinate[i];
    }
    return a.coordinate[dimension - 1] < b.coordinate[dimension - 1];
};

vector<Point> points;

/** 
 * solving functions
 */

void solve_wise() {
    bool flag = false;
    int dimension = points[0].dimension;
    int *max_record = (int*)malloc(dimension * sizeof(int));
    for (int i = 0; i < dimension; i ++)
        max_record[i] = INT32_MIN;
    vector<Point> result;
    sort(points.begin(), points.end(), pointReverseCmp);
    for (int i = 0; i < points.size(); i ++, flag = false) {
        for (int j = 1; j < dimension; j ++) {
            if (max_record[j] < points[i].coordinate[j]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            for (int j = 1; j < dimension; j ++)
                if (max_record[j] < points[i].coordinate[j])
                    max_record[j] = points[i].coordinate[j];
            result.emplace_back(points[i]);
        }
    }
    for (int i = 0; i < result.size(); i ++) {
        for (int c = 0; c < dimension; c ++)
            printf("%d ", result[i].coordinate[c]);
        cout << '\n';
    }
};

/**
 * main function
 */

int main() {

    int t, dimension = 3;

    cin >> t;
    for (int i = 0; i < t; i ++) {
        points.emplace_back(Point(dimension));
        for (int j = 0; j < dimension; j ++)
            cin >> points[i].coordinate[j];
    }

    solve_wise();

    return 0;
}
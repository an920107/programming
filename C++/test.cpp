#include <bits/stdc++.h>
using namespace std;

/** 
 * definition of struct point
 */

struct Point {
    int x, y, z;

    Point() {}
    Point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}

    inline bool dominates(Point &p) {
        return x >= p.x && y >= p.y && z >= p.z;
    }
};

auto pointCmpX = [](Point &a, Point &b) {
    if (a.x == b.x) {
        if (a.y == b.y) {
            return a.z < b.z;
        }
        else return a.y < b.y;
    }
    else return a.x < b.x;
};

vector<Point> points;

/** 
 * time function
 */

template<typename Func>
double run_time(Func &lambda) {
    long long start = clock();
    lambda();
    long long end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

/** 
 * solving functions
 */

auto solve_force = [](void) {
    bool flag = false;
    vector<Point> result;
    for (int i = 0; i < points.size(); i ++, flag = false) {
        for (int j = 0; j < points.size(); j ++) {
            if (i != j && points[j].dominates(points[i])) {
                flag = true;
                break;
            }
        }
        if (!flag) result.emplace_back(points[i]);
    }
    sort(result.begin(), result.end(), pointCmpX);
    // for (int i = result.size() - 1; i >= 0; i --)
    //     printf("%d %d %d\n", result[i].x, result[i].y, result[i].z);
};

auto solve_sorted_force = [](void) {
    bool flag = false;
    vector<Point> result;
    sort(points.begin(), points.end(), pointCmpX);
    for (int i = 0; i < points.size(); i ++, flag = false) {
        for (int j = i + 1; j < points.size(); j ++) {
            if (points[j].dominates(points[i])) {
                flag = true;
                break;
            }
        }
        if (!flag) result.emplace_back(points[i]);
    }
    // for (int i = result.size() - 1; i >= 0; i --)
    //     printf("%d %d %d\n", result[i].x, result[i].y, result[i].z);
};

/**
 * main function
 */

int main() {

    srand(time(NULL));
    int t = 5E6;
    vector<Point> points_copy(t);
    for (int i = 0; i < t; i ++) {
        points_copy[i].x = rand() % INT_MAX * -(rand() % 2 ? 1 : -1);
        points_copy[i].y = rand() % INT_MAX * -(rand() % 2 ? 1 : -1);
        points_copy[i].z = rand() % INT_MAX * -(rand() % 2 ? 1 : -1);
        printf("%6.2f %% %12d %12d %12d\n", (float)i / t * 100, points_copy[i].x, points_copy[i].y, points_copy[i].z);
    }
    // freopen("OJ/tmp/out.txt", "r", stdin);
    // int t;
    // cin >> t;
    // vector<Point> points_copy(t);
    // for (int i = 0; i < t; i ++)
    //     cin >> points_copy[i].x >> points_copy[i].y >> points_copy[i].z;
    // putchar('\n');

    
    points = points_copy;
    printf("solve_force: %.4lf s\n", run_time(solve_force));
    points = points_copy;
    printf("solve_sorted_force: %.4lf s\n", run_time(solve_sorted_force));
    return 0;
}
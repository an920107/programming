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
            if (i != j && points[j].dominate(points[i])) {
                flag = true;
                break;
            }
        }
        if (!flag) result.emplace_back(points[i]);
    }
    sort(result.begin(), result.end(), pointCmp);
    // int dimension = result[0].dimension;
    // for (int i = result.size() - 1; i >= 0; i --)
    //     for (int c = 0; c < dimension; c ++)
    //         printf("%d ", result[i].coordinate[c]);
};

auto solve_sorted_force = [](void) {
    bool flag = false;
    vector<Point> result;
    sort(points.begin(), points.end(), pointCmp);
    for (int i = 0; i < points.size(); i ++, flag = false) {
        for (int j = i + 1; j < points.size(); j ++) {
            if (points[j].dominate(points[i])) {
                flag = true;
                break;
            }
        }
        if (!flag) result.emplace_back(points[i]);
    }
    // int dimension = result[0].dimension;
    // for (int i = result.size() - 1; i >= 0; i --)
    //     for (int c = 0; c < dimension; c ++)
    //         printf("%d ", result[i].coordinate[c]);
};

/**
 * main function
 */

int main() {

    srand(time(NULL));
    int t = 1E4, dimension = 100;
    Point p(dimension);
    vector<Point> points_copy;
    printf("generating %d cases with %d dimensions...\n", t, dimension);
    for (int i = 0; i < t; i ++) {
        points_copy.emplace_back(Point(dimension));
        for (int c = 0; c < dimension; c ++)
            points_copy[i].coordinate[c] = rand() % INT_MAX * -(rand() % 2 ? 1 : -1);
        // printf("%6.2f %%\n", (float)i / t * 100);
    }
    // freopen("OJ/tmp/out.txt", "r", stdin);
    // int t;
    // cin >> t;
    // vector<Point> points_copy(t);
    // for (int i = 0; i < t; i ++)
    //     cin >> points_copy[i].x >> points_copy[i].y >> points_copy[i].z;
    // putchar('\n');

    printf("running solve_force...\n");
    points = points_copy;
    printf("solve_force: %.4lf s\n", run_time(solve_force));
    printf("running solve_sorted_force...\n");
    points = points_copy;
    printf("solve_sorted_force: %.4lf s\n", run_time(solve_sorted_force));
    return 0;
}
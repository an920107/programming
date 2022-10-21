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

auto pointXReverseCmp = [](Point &b, Point &a) {
    return a.coordinate[0] < b.coordinate[0];
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
    int dimension = result[0].dimension;
    for (int i = result.size() - 1; i >= 0; i --) {
        for (int c = 0; c < dimension; c ++)
            printf("%12d ", result[i].coordinate[c]);
        putchar('\n');
    }
};

void solve_3d() {
    bool *isMax = (bool*)malloc(points.size() * sizeof(bool));
    memset(isMax, 0, points.size() * sizeof(bool));
    vector<Point> projection;
    int maxZ = INT32_MIN;
    sort(points.begin(), points.end(), pointXReverseCmp);
    for (int i = 0; i < points.size(); i ++) {
        bool flag = false;
        for (auto &p : projection) {
            if 
        }
        if (!flag) {
            projection.emplace_back(Point(2));
            projection.back().coordinate[0] = points[i].coordinate[1];
            projection.back().coordinate[1] = points[i].coordinate[2];
            isMax[i] = true;
        }
    }
    for (int i = 0; i < points.size(); i ++) {
        if (isMax[i]) {
            for (int c = 0; c < 3; c ++)
                printf("%12d ", points[i].coordinate[c]);
            putchar('\n');
        }
    }
}

auto solve_wise = [](void) {
    if (points[0].dimension == 3)
        solve_3d();
};

/**
 * main function
 */

int main() {

    srand(time(NULL));
    int t = 20, dimension = 3;
    vector<Point> points_copy;

    // cin >> t;
    // for (int i = 0; i < t; i ++) {
    //     points_copy.emplace_back(Point(dimension));
    //     for (int j = 0; j < dimension; j ++)
    //         cin >> points_copy[i].coordinate[j];
    // }

    printf("generating %d cases with %d dimensions...\n", t, dimension);
    for (int i = 0; i < t; i ++) {
        points_copy.emplace_back(Point(dimension));
        for (int c = 0; c < dimension; c ++)
            points_copy[i].coordinate[c] = rand() % INT_MAX * -(rand() % 2 ? 1 : -1);
    }

    printf("running solve_force...\n");
    points = points_copy;
    printf("solve_force: %.4lf s\n", run_time(solve_force));
    printf("running solve_wise...\n");
    points = points_copy;
    printf("solve_wise: %.4lf s\n", run_time(solve_wise));
    return 0;
}
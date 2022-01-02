#include <bits/stdc++.h>
using namespace std;

#define long long long
typedef pair<long, long> pairl;

pairl arr[3000000];

double distance(const pairl &a, const pairl &b) {
    long x_d = a.first - b.first, y_d = a.second - b.second;
    return sqrt(x_d * x_d + y_d * y_d);
}

void solve() {
    long n;
    double res = 1E15;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i].first >> arr[i].second;
    }
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (res < arr[j].first - arr[i].first)
                break;
            res = min(res, distance(arr[i], arr[j]));
        }
    }
    printf("%.4lf\n", res);
}

int main() {
    solve();
    return 0;
}
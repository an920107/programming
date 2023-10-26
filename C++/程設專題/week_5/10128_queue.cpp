#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int solve(int n, int p, int r) {
    if (p <= 0 || r <= 0 || p > n || r > n) return 0;

    // [共 i 個人][前端可見 j 個][前端可見 k 個] 可組成的方法數
    vvvi methods(n + 1, vvi(p + 1, vi(r + 1)));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p, r;
        cin >> n >> p >> r;
    }

    return 0;
}
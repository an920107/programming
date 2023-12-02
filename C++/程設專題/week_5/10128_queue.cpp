#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int solve(int n, int p, int r) {
    if (p <= 0 || r <= 0 || p > n || r > n) return 0;

    vvvi method(n + 1, vvi(p + 1, vi(r + 1)));
    method[1][1][1] = 1;

    // 假設原有 i 個人，前端可見 j 人，後端可見 k 人，新進的人比目前任何人都矮：
    //
    // 1. 新的人放中間，有 (i - 1) 個位置可以放，再乘上原本的方法數
    //    -> method[i + 1][j][k] = (i - 1) * method[i][j][k]
    //    -> method[i][j][k] = (i - 2) * method[i - 1][j][k]
    // 2. 新的人放前端，前端從可見的人從 j 個變 j + 1 個，方法數與原本的相同
    //    -> method[i + 1][j + 1][k] = method[i][j][k]
    //    -> method[i][j][k] = method[i - 1][j - 1][k]
    // 3. 新的人放後端，前端從可見的人從 k 個變 k + 1 個，方法數與原本的相同
    //    -> method[i + 1][j][k + 1] = method[i][j][k]
    //    -> method[i][j][k] = method[i - 1][j][k - 1]
    //
    // 將三種可能相加，整理後得：
    // method[i][j][k] = (i - 2) * method[i - 1][j][k] +
    //                   method[i - 1][j - 1][k] +
    //                   method[i - 1][j][k - 1]

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= p; j++)
            for (int k = 1; k <= r; k++)
                method[i][j][k] = (i - 2) * method[i - 1][j][k] +
                                  method[i - 1][j - 1][k] +
                                  method[i - 1][j][k - 1];

    return method[n][p][r];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p, r;
        cin >> n >> p >> r;
        cout << solve(n, p, r) << "\n";
    }

    return 0;
}
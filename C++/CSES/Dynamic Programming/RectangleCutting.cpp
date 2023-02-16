#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int solve(int m, int n) {

    // dp[i][j]: 處理 i x j 的矩形需要幾個步驟
    // 初始化: dp[:][:] = INF; dp[i][i] = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= min(m, n); i ++)
        dp[i][i] = 0;

    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= n; j ++) {
            for (int cut = 1; cut < i; cut ++)
                dp[i][j] = min(dp[i][j], dp[cut][j] + dp[i - cut][j] + 1);
            for (int cut = 1; cut < j; cut ++)
                dp[i][j] = min(dp[i][j], dp[i][cut] + dp[i][j - cut] + 1);
        }
    }

    return dp[m][n];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    cout << solve(m, n) << '\n';

    return 0;
}
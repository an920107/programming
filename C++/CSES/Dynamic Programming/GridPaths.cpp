#include <bits/stdc++.h>
using namespace std;

const int MOD = 1E9 + 7;

int solve(int n, const vector<vector<char>> &grid) {
 
    // 跟 grid 一樣，會多一排一列
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    dp[0][1] = 1;

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {

            if (grid[i][j] != '.')
                continue;

            if (grid[i - 1][j] == '.')
                dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;
            if (grid[i][j - 1] == '.')
                dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }

    return dp[n][n];
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // grid[0][:], grid[:][0] 固定為 '.'
    // 即實際上數據的 index 是從 1 開始
    vector<vector<char>> grid(n + 1, vector<char>(n + 1, '.'));
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> grid[i][j];

    cout << solve(n, grid) << '\n';

    return 0;
}

// 操作方式：（假設沒有障礙物）
/**
 * 0 1 0 0
 * 0 0 0 0
 * 0 0 0 0
 * 0 0 0 0
 */
/**
 * 0 1 0 0
 * 0 1 1 1
 * 0 1 0 0
 * 0 1 0 0
 */
/**
 * 0 1 0 0
 * 0 1 1 1
 * 0 1 2 3
 * 0 1 3 0
 */
/**
 * 0 1 0 0
 * 0 1 1 1
 * 0 1 2 2
 * 0 1 2 6
 */
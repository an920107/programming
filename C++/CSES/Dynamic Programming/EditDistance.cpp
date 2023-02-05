#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline T min(T x, T y, T z) {
    return min(min(x, y), z);
}

int solve(string &from, string &to) {

    // dp size: [from.len() + 1][to.len() + 1]
    // dp[m][n]: 處理到該位置需要操作的步數
    vector<vector<int>> dp(from.length() + 1, vector<int>(to.length() + 1));
    for (int i = 0; i <= from.length(); i ++)
        dp[i][0] = i;
    for (int j = 0; j <= to.length(); j ++)
        dp[0][j] = j;

    // 將字串的 index 統一向後移 1，方便後面操作
    from.insert(0, "~");
    to.insert(0, "~");

    for (int i = 1; i < from.length(); i ++) {
        for (int j = 1; j < to.length(); j ++) {
            // 字尾相同的話，不用操作，直接相等於前一位
            if (from[i] == to[j])
                dp[i][j] = dp[i - 1][j - 1];
            // 字尾不同，取「刪除」「新增」「替換」最小者，加一步操作
            else {
                dp[i][j] = 1 + min(
                    dp[i][j - 1], // 新增
                    dp[i - 1][j], // 刪除
                    dp[i - 1][j - 1] // 替換
                );
            }
        }
    }

    from.erase(0, 1);
    to.erase(0, 1);

    return dp[from.length()][to.length()];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string from, to;
    cin >> from >> to;

    cout << solve(from, to) << '\n';

    return 0;
}
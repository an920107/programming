#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int solve(const int n) {

    // dp[i]：組成 i 花費的最小操作數
    // 初始化：dp[0] = 0, dp[1:] = INF
    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 0; i <= n; i ++) {
        for (char ch : to_string(i)) {
            const int digit = ch - '0';
            // 取「原本的操作數」與「扣掉某一位數的操作數 + 1」較小的
            // + 1 是因為這一次判斷算一個操作
            dp[i] = min(dp[i], dp[i - digit] + 1);
        }
    }

    return dp[n];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << solve(n) << '\n';
    
    return 0;
}
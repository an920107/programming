#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &coins, int goal) {

    // dp[i]：組成 i 元所需要的最少硬幣
    // 初始化：dp[0] = 0, dp[1:] = INF
    const int DP_SIZE = goal + 1;
    const int INF = 0x3f3f3f3f;
    vector<int> dp(DP_SIZE, INF);
    dp[0] = 0;

    for (auto &coin : coins) {

        // 這邊從前面往後
        // 是因為同樣的硬幣可以重複使用
        // 例如 10 元可以用 5 個 2 組成
        // 那麼每 2 個就要累計一次

        for (int i = coin; i <= goal; i ++)
            dp[i] = min(dp[i - coin] + 1, dp[i]);
    }

    return (dp[goal] < INF) ? dp[goal] : -1;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, goal;
    cin >> n >> goal;
    vector<int> coins(n);
    for (int i = 0; i < n; i ++)
        cin >> coins[i];
    cout << solve(coins, goal) << '\n';

    return 0;
}
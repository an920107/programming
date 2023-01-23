#include <bits/stdc++.h>
using namespace std;

const int MOD = 1E9 + 7;

int solve(vector<int> &coins, int goal) {

    // dp[i]：組成 i 元的組合數
    // 初始化：dp[0] = 1, dp[1:] = 0
    vector<int> combinationCount(goal + 1);
    combinationCount[0] = 1;

    for (int value = 1; value <= goal; value ++)
        for (auto &coin : coins)
            if (value >= coin)
                combinationCount[value] =
                    (combinationCount[value] + combinationCount[value - coin]) % MOD;
    
    return combinationCount[goal];
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
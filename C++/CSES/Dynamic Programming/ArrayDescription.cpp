#include <bits/stdc++.h>
using namespace std;

const int MOD = 1E9 + 7;

int solve(const vector<int> &nums, int upper) {

    // dp[i][j]：在陣列 i 的位置數字為 j 時的組合數
    // ( 0 <= j <= upper + 1 )
    // 初始化：
    // - 當 num[0] == 0 時，dp[0][:] = 1
    // - 否則 dp[0][num[0]] = 1
    // 其餘皆為 0
    vector<vector<int>> dp(nums.size(), vector<int>(upper + 2));
    if (nums[0] == 0)
        for (int i = 1; i <= upper; i ++)
            dp[0][i] = 1;
    else dp[0][nums[0]] = 1;

    for (int i = 1; i < nums.size(); i ++) {
        // 如果該位置是任意數，則所有可能都跑過一遍
        if (nums[i] == 0) {
            for (int j = 1; j <= upper; j ++)
                for (int delta = -1; delta <= 1; delta ++)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + delta]) % MOD;
        }
        // 否則只跑該位置的那個數 -1 ~ +1
        else {
            const int j = nums[i];
            for (int delta = -1; delta <= 1; delta ++)
                dp[i][j] = (dp[i][j] + dp[i - 1][j + delta]) % MOD;
        }
    }

    int result = 0;
    if (nums.back() == 0)
        for (int i = 1; i <= upper; i ++)
            result = (result + dp[nums.size() - 1][i]) % MOD;
    else result = dp[nums.size() - 1][nums.back()];

    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, upper;
    cin >> n >> upper;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
        cin >> nums[i];
    cout << solve(nums, upper) << '\n';

    return 0;
}
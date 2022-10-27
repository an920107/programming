#include <bits/stdc++.h>
using namespace std;

#define MAX_N_COUNT 100

void solve(int n, int m, vector<int> &nums) {
    bool dp[MAX_N_COUNT][MAX_N_COUNT * MAX_N_COUNT]{false};
    dp[0][0] = true;
    int maxProduct = INT_MIN;
    int minProduct = INT_MAX;
    int sum = 0;
    for (auto &num : nums)
        sum += num;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, tmp;
    vector<int> nums;
    while (cin >> n >> m) {
        nums.clear();
        for (int i = 0; i < n + m; i ++) {
            cin >> tmp;
            nums.emplace_back(tmp);
        }
        solve(n, m, nums);
    }
    return 0;
}
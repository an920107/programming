#include <bits/stdc++.h>
using namespace std;

#define MAX_N_COUNT 100
#define MAX_SUM 10000

void solve(int sideMax, vector<int> &nums) {
    int maxProduct = INT_MIN;
    int minProduct = INT_MAX;
    int sum = 0;
    for (int i = 0; i < nums.size(); i ++) {
        sum += nums[i];
        nums[i] += 50;
    }
    bool available[MAX_N_COUNT + 1][MAX_SUM + 1]{false};
    int status[MAX_N_COUNT + 1][MAX_SUM + 1]{0};
    available[0][0] = true;
    for (int i = 0; i < nums.size(); i ++) {
        for (int n = 0; n <= sum; n ++) {
            if (available[i][n] && status[i][n] < sideMax) {
                available[i + 1][n] = 
            }
        }
    }
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
        solve(n, nums);
    }
    return 0;
}
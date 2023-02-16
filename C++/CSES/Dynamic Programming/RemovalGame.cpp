#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int>& nums) {

    map<int, int> dp;

    for (int i = 0; i <= nums.size() / 2; i ++) {
        
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
        cin >> nums[i];

    cout << solve(nums) << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums) {
    int count = 1;

    // pos[i]：數字 i 在 nums 的位置 (從 0 開始)
    vector<int> pos(nums.size());
    for (int i = 0; i < nums.size(); i ++)
        pos[nums[i] - 1] = i;
    
    // 如果 i 的位置小於 i - 1 的
    // 代表需要多一次 round
    for (int i = 1; i < nums.size(); i ++)
        if (pos[i] < pos[i - 1])
            count ++;
    
    cout << count << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
        cin >> nums[i];
    solve(nums);

    return 0;
}

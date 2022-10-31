#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums) {
    int count = 1;
    vector<int> pos(nums.size());
    for (int i = 0; i < nums.size(); i ++)
        pos[nums[i] - 1] = i;
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

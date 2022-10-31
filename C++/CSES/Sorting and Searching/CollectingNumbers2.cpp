#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, vector<pair<int, int>> &swaps) {
    int count = 1;
    vector<int> pos(nums.size());
    for (int i = 0; i < nums.size(); i ++)
        pos[nums[i] - 1] = i;
    for (int i = 1; i < nums.size(); i ++)
        if (pos[i] < pos[i - 1])
            count ++;
    for (auto &p : swaps) {

        cout << count << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    vector<pair<int, int>> swaps(m);
    for (int i = 0; i < n; i ++)
        cin >> nums[i];
    for (int i = 0, x, y; i < m; i ++) {
        cin >> x >> y;
        swaps[i] = make_pair(x, y);
    }
    solve(nums, swaps);

    return 0;
}

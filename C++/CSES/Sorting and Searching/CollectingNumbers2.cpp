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
    
    for (auto &[xIndex, yIndex] : swaps) {

        int xNum = nums[xIndex - 1];
        int yNum = nums[yIndex - 1];

        set<pair<int, int>> numPairSet;
        if (xNum > 1)
            numPairSet.insert(make_pair(xNum - 1, xNum));
        if (xNum < nums.size())
            numPairSet.insert(make_pair(xNum, xNum + 1));
        if (yNum > 1)
            numPairSet.insert(make_pair(yNum - 1, yNum));
        if (yNum < nums.size())
            numPairSet.insert(make_pair(yNum, yNum + 1));

        // 先看原本有沒有 reversion 從 count 扣掉
        for (auto &[left, right] : numPairSet)
            if (pos[left - 1] > pos[right - 1])
                count --;

        // 交換
        swap(nums[xIndex - 1], nums[yIndex - 1]);
        swap(pos[xNum - 1], pos[yNum - 1]);

        // 再統計一次 reversion 加到 count 上
        for (auto &[left, right] : numPairSet)
            if (pos[left - 1] > pos[right - 1])
                count ++;

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

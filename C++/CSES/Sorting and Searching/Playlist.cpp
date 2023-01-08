#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums) {
    map<int, int> lastAppear;
    int result = 0, count = 0;
    for (int i = 0; i < nums.size(); i ++) {
        // nums[i] has appeared
        if (lastAppear.find(nums[i]) != lastAppear.end()) {
            int distance = i - lastAppear[nums[i]];
            if (distance > count);
                count = distance;
        }
        else count ++;
        if (count > result)
            result = count;
        lastAppear[nums[i]] = i;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
        cin >> nums[i];
    cout << solve(nums) << endl;

    return 0;
}
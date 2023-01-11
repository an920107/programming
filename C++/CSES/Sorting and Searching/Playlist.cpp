#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums) {
    const int len = nums.size();
    int result = 0;
    set<int> appeared;

    int left = 0, right = 0;
    while (left < len && right < len) {
        // nums[right] hasn't appeared.
        while (right < len && appeared.count(nums[right]) == 0) {
            appeared.insert(nums[right]);
            result = max(result, right - left + 1);
            right ++;
        }
        
        // nums[right] has appeared.
        while (right < len && appeared.count(nums[right]) > 0) {
            appeared.erase(nums[left]);
            left ++;
        }
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
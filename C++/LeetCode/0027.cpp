#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = nums.size();
        for (int i = 0; i < last; ++ i) {
            if (nums[i] == val) {
                nums[i --] = nums[-- last];
            }
        }
        return last;
    }
};

int main() {
    
    vector<int> nums;
    nums.emplace_back(2);
    nums.emplace_back(3);
    nums.emplace_back(3);
    nums.emplace_back(2);

    Solution sol;
    cout << sol.removeElement(nums, 3) << endl;
    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}
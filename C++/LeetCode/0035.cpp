#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size() - 1;
        int mid = upper / 2;
        while (true) {

            if (upper == lower) {
                if (target > nums[mid])
                    return mid + 1;
                else return mid;
            }

            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                lower = mid + 1;
            else upper = mid;
            mid = (lower + upper) / 2;
        }
    }
};

int main() {
    
    vector<int> nums{1,3};

    Solution sol;
    cout << sol.searchInsert(nums, 0) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, last = m + n;
        while (j >= 0 && last > 0) {
            if (i >= 0 && nums1[i] > nums2[j])
                nums1[-- last] = nums1[i --];
            else nums1[-- last] = nums2[j --];
        }
        return;
    }
};

int main() {
    
    Solution sol;
    // vector<int> nums1{1,2,3,0,0,0};
    // vector<int> nums2{2,4,5};
    // sol.merge(nums1, 3, nums2, 3);
    vector<int> nums1{0};
    vector<int> nums2{1};
    sol.merge(nums1, 0, nums2, 1);
    for (auto &x : nums1)
        cout << x << " ";
    cout << endl;

    return 0;
}
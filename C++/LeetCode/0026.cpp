#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int acc = 1;
        for (int i = 0; i < nums.size() - 1; i ++) {
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                i ++;
            };
            if (i == nums.size() - 1) break;
            nums[acc] = nums[i + 1];
            acc ++;
        }
        return acc;
    }
};

int main() {
    
    // vector<int> vec{0,0,1,1,1,2,2,3,3,4};
    vector<int> vec{0,0,1,1};
    Solution sol;
    int k = sol.removeDuplicates(vec);
    cout << k << endl;
    for (int i = 0 ; i < k; i ++)
        cout << vec[i] << endl;

    return 0;
}
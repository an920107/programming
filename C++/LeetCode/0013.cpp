#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        vector<int> nums;
        for (char& x : s) {
            switch (x) {
                case 'I': nums.emplace_back(1); break;
                case 'V': nums.emplace_back(5); break;
                case 'X': nums.emplace_back(10); break;
                case 'L': nums.emplace_back(50); break;
                case 'C': nums.emplace_back(100); break;
                case 'D': nums.emplace_back(500); break;
                case 'M': nums.emplace_back(1000); break;
                default: break;
            }
        }
        int ans = 0, i = 0;
        for (; i < nums.size() - 1; i ++) {
            if (nums[i] >= nums[i + 1])
                ans += nums[i];
            else {
                ans += nums[i + 1] - nums[i];
                i ++;
            }
        }
        if (i == nums.size() - 1) ans += nums[i];
        return ans;
    }
};

int main() {
    
    Solution sol;
    cout << sol.romanToInt("MCMXCIV") << endl;

    return 0;
}

/**
 * I -> 1
 * V -> 5
 * X -> 10
 * L -> 50
 * C -> 100
 * D -> 500
 * M -> 1000
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool c = 1;
        vector<int> ans;
        for (int i = digits.size() - 1; i >= 0; -- i) {
            if (digits[i] + c < 10) {
                ans.emplace_back(digits[i] + c);
                c = 0;
            }
            else {
                ans.emplace_back(0);
                c = 1;
            }
        }
        if (c) ans.emplace_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    
    vector<int> digits{1, 2, 4};
    Solution sol;
    for (int x : sol.plusOne(digits))
        cout << x;
    cout << endl;

    return 0;
}
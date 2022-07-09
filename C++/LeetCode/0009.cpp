#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(long long x) {
        if (x < 0) return false;
        if (x >= 0 && x <= 9) return true;
        long long y = 0;
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
            if (y == 0) break;
            if (x == y) return true;
            if (x / 10 == y) return true;
            if (x < y) break;
        }
        return false;
    }
};

int main() {
    
    Solution sol;
    cout << sol.isPalindrome(21120) << endl;

    return 0;
}
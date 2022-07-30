#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        for (long long i = 1; i <= x + 1; ++ i) {
            if (i * i > (long long)(x)) return i - 1;
        }
        return 0;
    }
};

int main() {
    
    Solution sol;
    cout << sol.mySqrt(2147395600) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int lower = 1;
        int upper = 46341;
        int mid = 23171;
        while (true) {
            if (upper == lower) return mid - 1;
            int mul = mid * mid;
            if (mul < x) lower = mid + 1;
            else if (mul == x) return mid;
            else upper = mid;
            mid = (upper + lower) / 2;
        }
        return 46340;
    }
};

int main() {
    
    Solution sol;
    for (int i = 0; i <= 100; i ++) {
        printf("%-4d%-3d%-3d\n", i, sol.mySqrt(i), int(sqrt(i)));
    }

    return 0;
}
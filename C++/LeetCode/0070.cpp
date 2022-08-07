// Dynamic Programming
// https://www.youtube.com/watch?v=Y0lT9Fck7qI

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        this->n = n;
        return f(1, 1, 2);
    }

private:
    int n;

    int f(int n1, int n2, int acc) {
        if (acc > n) return n2;
        return f(n2, n1 + n2, acc + 1);
    }
};

int main() {

    Solution sol;
    cout << sol.climbStairs(5) << endl;

    return 0;
}

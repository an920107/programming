#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int sub = a.length() - b.length();
        string sum, zeros;
        for (int i = 0; i < abs(sub); ++ i)
            zeros += "0";
        if (sub < 0) a = zeros + a;
        else if (sub > 0) b = zeros + b;
        for (int i = 0; i < a.length(); ++ i) {
            sum += a[i] + b[i] - '0';
        }
        for (int i = sum.length() - 1; i > 0; -- i) {
            if (sum[i] >= '2') {
                sum[i] -= 2;
                sum[i - 1] ++;
            }
        }
        if (sum[0] >= '2') {
            sum[0] -= 2;
            sum = "1" + sum;
        }
        return sum;
    }
};

int main() {
    
    Solution sol;
    cout << sol.addBinary("111", "111") << endl;

    return 0;
}
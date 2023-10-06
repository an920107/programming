// referance:
// https://zhuanlan.zhihu.com/p/131640888?fbclid=IwAR3I4vVCiSE_w8p4JYJjDUGMGf8c8s-_qB_pxmcr701GCEq8q9l_8UxRQtw

#include <bits/stdc++.h>
using namespace std;

int solve(string &str) {
    const int length = str.length();
    str += str;
    int i = 0, j = 1, k = 0;
    while (i < length && j < length && k < length) {
        int difference = str[i + k] - str[j + k];
        // 兩者等大
        if (difference == 0)
            k++;
        else {
            // 前者較大
            if (difference > 0) i += k + 1;
            // 後者較大
            else
                j += k + 1;

            if (i == j) j++;
            k = 0;
        }
    }
    return min(i, j);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string line;
        cin >> line;
        cout << solve(line) + 1 << "\n";
    }
    return 0;
}

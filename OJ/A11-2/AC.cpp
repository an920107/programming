#include <bits/stdc++.h>
using namespace std;

struct Result {
    string text = "";
    int length = 0;
};

bool IsPalindrome(string str) {
    string rvs = str;
    reverse(rvs.begin(), rvs.end());
    return str == rvs;
}

Result Solve(string str) {
    Result res;
    int end, str_len = str.length();
    for (int len = str_len; len >= 2; len --) {
        for (int i = 0; i <= str_len - len; i ++) {
            if (IsPalindrome(str.substr(i, len))) {
                res.length = len;
                res.text = str.substr(i, len);
                return res;
            }
        }
    }
    res.text = "Palindrome not existed!";
    return res;
}

int main() {
    string str;
    Result res;
    while (cin >> str) {
        if (str == "-1") break;
        res = Solve(str);
        if (res.length > 0) {
            cout << res.text << "\n";
            cout << res.length << "\n\n";
        }
        else cout << res.text << "\n\n";
    }
    return 0;
}

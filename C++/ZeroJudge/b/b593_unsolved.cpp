#include <bits/stdc++.h>
using namespace std;

int solve(const string &str) {
    for (int i = str.length() - 1; i > 0; i --) {
        if (str[i] < str[i - 1]) return 0;
    }
    
}

int main() {
    string str;
    while (cin >> str) {
        if (str == "0") break;
        cout << solve(str) << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int solve(const string &text) {
    vector<int> factors;
    for (int len = 1; len < text.length(); len++)
        if (text.length() % len == 0) factors.emplace_back(len);

    for (auto len : factors) {
        bool found = true;
        string substr = text.substr(0, len);
        for (int i = len; i < text.length(); i += len) {
            if (substr != text.substr(i, len)) {
                found = false;
                break;
            }
        }
        if (found) return text.length() / len;
    }
    return 1;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == ".") break;
        cout << solve(line) << "\n";
    }

    return 0;
}
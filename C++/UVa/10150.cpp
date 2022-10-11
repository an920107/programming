#include <bits/stdc++.h>
using namespace std;

vector<string> dict;

void solve(string &line) {
    int splitIndex = line.find(' ');
    string from = line.substr(0, splitIndex);
    string to = line.substr(splitIndex + 1, line.length() - splitIndex);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    bool flag = false;
    string line;
    while (getline(cin, line)) {
        if (line == "") break;
        dict.emplace_back(line);
    }
    sort(dict.begin(), dict.end());
    while (getline(cin, line)) {
        if (line == "") break;
        if (flag) cout << '\n';
        else flag = true;
        solve(line);
    }

    return 0;
}
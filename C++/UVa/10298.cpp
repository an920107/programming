#include <bits/stdc++.h>
using namespace std;

void solve(string &str) {
    int prefix_len = 0;
    vector<int> failure_table;
    failure_table.emplace_back(-1);
    for(int i = 1, j = -1 ; i < str.length() ; i ++){
        while (j >= 0 && str[j + 1] != str[i])
            j = failure_table[j];
        if (str[j + 1] == str[i]) j ++;
        failure_table.emplace_back(j);
    }
    int repeat_len = str.length() - failure_table[str.length() - 1] - 1;
    if (str.length() % repeat_len)
        cout << "1\n";
    else cout << str.length() / repeat_len << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    while (cin >> str && str != ".")
        solve(str);
    return 0;
}
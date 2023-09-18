#include <bits/stdc++.h>
using namespace std;

vector<bool> solve(string str, vector<pair<int, int>> &query) {
    vector<int> interval(str.length(), 0);
    for (int i = 1; i < str.length(); i++) {
        if (str[i] != str[i - 1])
            interval[i] = interval[i - 1] + 1;
        else
            interval[i] = interval[i - 1];
    }
    vector<bool> result(query.size());
    for (int i = 0; i < query.size(); i++)
        result[i] = interval[query[i].first] == interval[query[i].second];
}

int main() {
    int case_count = 0;
    string str;
    while(getline(cin, str)) {
        if (str == "") continue;

        int query_count;
        cin >> query_count;
        vector<pair<int, int>> query(query_count);
        for (int i = 0; i < query_count; i++)
            cin >> query[i].first >> query[i].second;
        
        cout << "Case " << (++case_count) << ":\n";
        for (auto b : solve(str, query))
            cout << (b ? "Yes" : "No") << "\n";
    }
    return 0;
}
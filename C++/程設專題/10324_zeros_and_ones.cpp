#include <bits/stdc++.h>
using namespace std;

vector<bool> solve(string str, int count, vector<pair<int, int>> &query) {
    vector<int> prefix_sum(str.size() + 1);
    prefix_sum[0] = 0;
    for (int i = 0; i < str.size(); i++)
        prefix_sum[i + 1] = prefix_sum[i] + str[i] - '0';

    vector<bool> result;
    for (auto &p : query) {
        if (p.first > p.second)
            swap(p.first, p.second);
        int interval_sum = prefix_sum[p.second + 1] - prefix_sum[p.first];
        result.emplace_back(interval_sum == p.second - p.first + 1 || interval_sum == 0);
    }
    return result;
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
        for (auto b : solve(str, query_count, query))
            cout << (b ? "Yes" : "No") << "\n";
    }
    return 0;
}
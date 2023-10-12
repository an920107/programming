#include <bits/stdc++.h>
using namespace std;

vector<int> find_others(int from, const vector<int> &sums) {
    multiset<int> sums_set;
    for (auto x : sums) sums_set.insert(x);
    vector<int> params(1, from);
    while (!sums_set.empty()) {
        int next = *sums_set.begin() - params[0];
        for (auto x : params) {
            auto iter = sums_set.find(next + x);
            if (iter != sums_set.end())
                sums_set.erase(iter);
            else
                return vector<int>(0);
        }
        params.emplace_back(next);
    }
    return params;
}

vector<int> solve(vector<int> &sums) {
    sort(sums.begin(), sums.end());
    int offset = sums[0] < 0 ? -sums[0] * 2 : 0;
    transform(sums.begin(), sums.end(), sums.begin(),
              [&](int x) { return x + offset; });
    vector<int> result;
    for (int i = 0; i <= sums[0] / 2; i++) {
        result = find_others(i, sums);
        if (result.size() > 0) break;
    }
    transform(result.begin(), result.end(), result.begin(),
              [&](int x) { return x - offset / 2; });
    return result;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> sums(n * (n - 1) / 2);
        for (int i = 0; i < sums.size(); i++) cin >> sums[i];
        auto result = solve(sums);
        if (!result.empty())
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << (i < result.size() - 1 ? " " : "\n");
        else
            cout << "Impossible\n";
    }

    return 0;
}
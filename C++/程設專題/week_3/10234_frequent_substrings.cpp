#include <bits/stdc++.h>
using namespace std;

struct Result {
    int count;
    string substr;

    Result(int __count, const string &__substr)
        : count(__count), substr(__substr) {}

    Result() : Result(0, "") {}
};

vector<Result> solve(const string &__text, const vector<int> &__query_lens) {
    vector<Result> results;
    for (auto len : __query_lens) {
        map<string, int> substr_count;
        for (int i = 0; i < __text.length(); i++) {
            string substr = __text.substr(i, len);
            if (substr.length() == len) substr_count[substr]++;
        }

        int max_substr_count = 0;
        string max_substr;
        for (auto &p : substr_count) {
            if (p.second > max_substr_count) {
                max_substr_count = p.second;
                max_substr = p.first;
            }
        }
        results.emplace_back(max_substr_count, max_substr);
    }
    return results;
}

int main() {
    string line;
    while (getline(cin, line)) {
        for (int i = 0; i < line.length(); i++)
            if (line[i] >= 'A' && line[i] <= 'Z') line[i] += 'a' - 'A';
        int t;
        cin >> t;
        vector<int> lens(t);
        for (int i = 0; i < t; i++) cin >> lens[i];
        for (auto result : solve(line, lens))
            cout << result.count << " " << result.substr << "\n";
        cin.ignore();
    }
    return 0;
}
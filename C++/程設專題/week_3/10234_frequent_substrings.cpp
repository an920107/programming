// reference: https://sam571128.codes/2020/10/02/Suffix-Array/

#include <bits/stdc++.h>
using namespace std;

struct Result {
    int count;
    string substr;

    Result(int, const string &);
    Result();
};

class Solve {
   private:
    string text;
    vector<int> query_lens, suffix_array;

    int lcp(int, int);

   public:
    Solve(const string &, const vector<int> &);
    vector<Result> solve();
};

int main() {
    string line;
    while (getline(cin, line)) {
        for (int i = 0; i < line.length(); i++)
            if (line[i] >= 'A' && line[i] <= 'Z') line[i] += 'a' - 'A';
        int t;
        cin >> t;
        vector<int> lens(t);
        for (int i = 0; i < t; i++) cin >> lens[i];
        for (auto result : Solve(line, lens).solve())
            cout << result.count << " " << result.substr << "\n";
        cin.ignore();
    }
    return 0;
}

Result::Result(int __count, const string &__str)
    : count(__count), substr(__str) {}

Result::Result() : Result(0, "") {}

int Solve::lcp(int a, int b) {
    string str_a = text.substr(a), str_b = text.substr(b);
    for (int i = 0; i < min(str_a.length(), str_b.length()); i++)
        if (str_a[i] != str_b[i]) return i;
    return min(str_a.length(), str_b.length());
}

Solve::Solve(const string &__text, const vector<int> &__query_lens)
    : text(__text), query_lens(__query_lens), suffix_array(__text.length()) {
    // build suffix array
    for (int i = 0; i < text.length(); i++) suffix_array[i] = i;
    sort(suffix_array.begin(), suffix_array.end(),
         [&](int a, int b) { return text.substr(a) < text.substr(b); });
}

vector<Result> Solve::solve() {
    vector<Result> results;
    for (auto len : query_lens) {
        map<string, int> substr_count;
        for (int i = 0; i < suffix_array.size(); i++) {
            string substr = text.substr(suffix_array[i], len);
            if (substr.length() == len)
                substr_count[text.substr(suffix_array[i], len)]++;
        }

        int max_substr_conut = 0;
        string max_substr;
        for (auto &p : substr_count) {
            if (p.second > max_substr_conut) {
                max_substr_conut = p.second;
                max_substr = p.first;
            }
        }
        results.emplace_back(max_substr_conut, max_substr);
    }
    return results;
}
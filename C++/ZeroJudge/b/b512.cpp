#include <bits/stdc++.h>
using namespace std;

#define long long long

int main() {
    map<long, long> mp;
    string str;
    stringstream stream;
    char tmp_c;
    long res = 0, key, value;
    while (cin >> str) {
        if (str == "0:0") break;
        stream.clear();
        stream << str;
        stream >> key >> tmp_c >> value;
        mp.insert(pair<long, long>(key, value));
    }
    while (cin >> str) {
        if (str == "0:0") break;
        stream.clear();
        stream << str;
        stream >> key >> tmp_c >> value;
        if (mp.count(key)) {
            res += mp[key] * value;
        }
    }
    cout << res << "\n";
    return 0;
}
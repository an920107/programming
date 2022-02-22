#include <iostream>
#include <cstring>
#include <sstream>
#include <set>
using namespace std;

void solve(string &str) {
    stringstream sstream;
    multiset<int> mst;
    set<int> st;
    int n = 0, tmp;
    sstream << str;
    while (sstream >> tmp) {
        n ++;
        st.insert(tmp);
        mst.insert(tmp);
    }
    for (auto &elm : st) {
        if (mst.count(elm) > n / 2) {
            cout << elm << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    string str;
    while (getline(cin, str)) {
        solve(str);
    }
    return 0;
}

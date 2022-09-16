#include <bits/stdc++.h>
using namespace std;

void solve(int t) {

    set<string> st;
    vector<set<char>> vec;
    set<char> st_i, st_o;
    string str;
    bool flag;
    
    vec.clear();
    while (getline(cin, str)) {
        if (str == "") break;
        st.insert(str);
    }
    for (auto &s : st) {
        st_i.clear();
        flag = false;
        for (auto &ch : s)
            st_i.insert(ch);
        for (auto &elm : vec) {
            st_o.clear();
            set_intersection(st_i.begin(), st_i.end(), elm.begin(), elm.end(), inserter(st_o, st_o.begin()));
            if (!st_o.empty()) {
                for (auto &ch : st_i)
                    elm.insert(ch);
                flag = true;
                break;
            }
        }
        if (!flag)
            vec.emplace_back(st_i);
    }
    cout << vec.size() << "\n\n";

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    int t;
    
    cin >> t;
    getline(cin, str);
    getline(cin, str);
    while (t --) {
        solve(t);
    }

    return 0;
}

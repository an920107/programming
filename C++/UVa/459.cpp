#include <bits/stdc++.h>
using namespace std;

void solve(const int &t) {

    map<char, int> mp;
    string str;
    int index = 0;

    getline(cin, str);
    mp.insert(make_pair(str[0], index ++));
    while (getline(cin, str)) {
        if (str == "") break;
        for (auto &ch : str) {
            if (mp.find(ch) == mp.end()) {
                mp.insert(make_pair(ch, index ++));
            }
            else 
        }
    }

}

void dfs(int &n, int r, int l) {

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

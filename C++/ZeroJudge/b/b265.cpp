#include <bits/stdc++.h>
using namespace std;

int main() {
    map<set<int>, int> mp;
    set<int> st;
    int n, tmp, res;
    while (cin >> n) {
        if (n == 0) break;
        mp.clear();
        for (int i = 0; i < n; i ++) {
            st.clear();
            for (int j = 0; j < 5; j ++) {
                cin >> tmp;
                st.insert(tmp);
            }
            if (mp.count(st)) mp[st] ++;
            else mp.insert(pair<set<int>, int>(st, 1));
        }
        tmp = 0; res = 0;
        for (auto &obj : mp) {
            if (obj.second > tmp) tmp = obj.second;
        }
        for (auto &obj : mp) {
            if (obj.second == tmp) res += tmp;
        }
        cout << res << "\n";
    }    
    return 0;
}

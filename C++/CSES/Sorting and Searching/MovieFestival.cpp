#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<pair<int, int>> st, st_r;
    multimap<int, int> mp, mp_r;
    int n, result = -1;
    cin >> n;
    for (int i = 0, tmp_x, tmp_y; i < n; i ++) {
        cin >> tmp_x >> tmp_y;
        st.insert(pair<int, int>(tmp_x, tmp_y));
        st_r.insert(pair<int, int>(tmp_y, tmp_x));
    }
    st.insert(pair<int, int>(0, 1));
    for (auto &iter : st) {
        mp.insert(pair<int, int>(iter.first, iter.second));
    }
    for (auto &iter : st_r) {
        mp_r.insert(pair<int, int>(iter.first, iter.second));
    }
    for (auto iter_x = mp.begin(); iter_x != mp.end(); ) {
        result ++;
        auto iter_y = mp_r.upper_bound(iter_x->second);
        while (iter_y->second < iter_x->second && iter_y != mp_r.end()) {
            iter_y ++;
        }
        if (iter_y == mp_r.end()) break;
        iter_x = mp.find(iter_y->second);
    }
    cout << result << "\n";
    return 0;
}

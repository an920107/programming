#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> mp;
    set<int> st;
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> tmp;
        if (mp.count(tmp)) mp[tmp] ++;
        else mp.insert(pair<int, int>(tmp, 1));
    }
    tmp = 0;
    for (auto &obj : mp) {
        if (obj.second > tmp) tmp = obj.second;
    }
    for (auto &obj : mp) {
        if (obj.second == tmp) printf("%d %d\n", obj.first, tmp);
    }
    return 0;
}
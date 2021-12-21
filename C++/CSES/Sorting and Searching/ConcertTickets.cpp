#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    multiset<int, greater<int>> ticket;
    int n, m, tmp;
    bool flag = false;
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        cin >> tmp;
        ticket.insert(tmp);
    }
    for (int i = 0; i < m; i ++) {
        cin >> tmp;
        auto iter = ticket.lower_bound(tmp);
        if (iter != ticket.end()) {
            cout << *iter << "\n";
            ticket.erase(iter);
        }
        else cout << "-1\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void Solve() {
    multimap<int, int> mp;
    int n, target, tmp;
    cin >> n >> target;
    for (int i = 1; i <= n; i ++) {
        cin >> tmp;
        mp.insert(pair<int, int>(tmp, i));
    }
    for (auto iter_x = mp.begin(); iter_x != mp.end(); iter_x ++) {
        auto iter_y = mp.find(target - iter_x->first);
        if (iter_y == iter_x) {
            iter_y ++;
            if (iter_x->first + iter_y->first != target) {
                continue;
            }
        }
        if (iter_y != mp.end()) {
            printf("%d %d\n", iter_x->second, iter_y->second);
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    Solve();
    return 0;
}

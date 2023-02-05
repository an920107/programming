#include <bits/stdc++.h>
using namespace std;

void solve(const vector<int> &coins) {

    set<int> sums;
    sums.insert(0);

    for (auto &coin : coins) {
        set<int> newSums(sums);
        for (auto &sum : sums)
            newSums.insert(sum + coin);
        sums = newSums;
    }

    cout << sums.size() - 1 << '\n';
    for (auto iter = next(sums.begin()); iter != sums.end(); iter ++)
        cout << *iter << ' ';
    cout << '\n';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i ++)
        cin >> coins[i];
    
    solve(coins);

    return 0;
}
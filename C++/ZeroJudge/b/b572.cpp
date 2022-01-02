#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int t;
    pair<int, int> x, y;
    cin >> x.first >> x.second >> y.first >> y.second >> t;
    return (y.first * 60 + y.second - x.first * 60 - x.second >= t);

}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i ++) {
        cout << (solve() ? "Yes\n" : "No\n");
    }
    return 0;
}
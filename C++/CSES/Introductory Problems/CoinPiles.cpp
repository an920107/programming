#include <bits/stdc++.h>
using namespace std;

#define llong long long

void solve(const llong &x, const llong &y) {
    const llong xyMin = min(x, y);
    const llong xyAbs = abs(x - y);
    if (xyMin - xyAbs >= 0 && (xyMin - xyAbs) % 3 == 0)
        cout << "YES\n";
    else cout << "NO\n";
}

int main () {
    int t;
    llong x, y;
    cin >> t;
    while (t --) {
        cin >> x >> y;
        solve(x, y);
    }
    return 0;
}

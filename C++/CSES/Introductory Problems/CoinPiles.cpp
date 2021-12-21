#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    long long x, y;
    for (cin >> t; t > 0; t --) {
        cin >> x >> y;
        if (min(x, y) - abs(x - y) >= 0 && (min(x, y) - abs(x - y)) % 3 == 0)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

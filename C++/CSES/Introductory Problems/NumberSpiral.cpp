#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, x, y, layer;
    for (cin >> n; n > 0; n --) {
        cin >> y >> x;
        layer = max(x, y);
        cout << layer * (layer - 1) + 1 + 
            (x - y) * (layer % 2 ? 1 : -1) << '\n';
    }
    return 0;
}
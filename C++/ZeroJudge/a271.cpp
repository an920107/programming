#include <bits/stdc++.h>
using namespace std;

int solve();

int main() {
    int t, res; cin >> t;
    for (int i = 0; i < t; i ++) {
        res = solve();
        if (res > 0) cout << res << "g\n";
        else cout << "bye~Rabbit\n";
    }
    return 0;
}

int solve() {
    int x, y, z, w, n, m, poison = 0;
    int carrot;
    string str;
    stringstream sstream;
    sstream.clear();
    cin >> x >> y >> z >> w >> n >> m;
    getline(cin, str);
    getline(cin, str);
    sstream << str;
    while (sstream >> carrot) {
        m -= poison * n;
        if (m <= 0) return 0;
        switch (carrot) {
            case 1: m += x; break;
            case 2: m += y; break;
            case 3: m -= z; break;
            case 4: m -= w; poison ++; break;
            default: break;
        }
        if (m <= 0) return 0;
    }
    return m;
}

/**
 * 1 -> x (+)
 * 2 -> y (+)
 * 3 -> z (-)
 * 4 -> w (-, p)
 * 0 -> NONE
 */
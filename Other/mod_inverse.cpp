#include <bits/stdc++.h>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int b, m, tmp;
    cin >> b >> m;
    for (int i = 1; ; i ++) {
        tmp = b * i % m;
        if (tmp == 1) {
            cout << i;
            break;
        }
    }
    return 0;
}

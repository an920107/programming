#include <bits/stdc++.h>
using namespace std;

long long coin[200000];
int n;

long long solve() {
    long long res = 1;
    sort(coin, coin + n);
    if (coin[0] != 1) return 1;
    for (int i = 0; i < n; i ++) {
        if (res < coin[i]) return res;
        res += coin[i];
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> coin[i];
    }
    cout << solve() << "\n";
    return 0;
}

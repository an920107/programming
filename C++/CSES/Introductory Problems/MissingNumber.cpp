#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long sum, n, k;
    cin >> n;
    sum = (n * (n + 1)) / 2;
    for (long long i = 0; i < n - 1; i ++) {
        cin >> k;
        sum -= k;
    }
    cout << sum << '\n';
    return 0;
}

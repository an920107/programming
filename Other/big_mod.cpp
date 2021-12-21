#include <bits/stdc++.h>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    vector<bool> n_bin;
    int b, n, m;
    cout << "count (b^n mod m)\ninput b n m: ";
    cin >> b >> n >> m;
    while (n > 0) {
        n_bin.push_back(n % 2);
        n /= 2;
    }
    int n_len = n_bin.size();
    reverse(n_bin.begin(), n_bin.end());

    int x = 1, p = b % m;

    for (int i = 0; i < n_len; i ++) {
        if (n_bin[n_len - i - 1]) x = (x * p) % m;
        p = (p * p) % m;
    }
    cout << "result = " << x << '\n';
    return 0;
}


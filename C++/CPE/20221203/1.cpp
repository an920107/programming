#include <bits/stdc++.h>
using namespace std;

const size_t bs_size = 35;

void solve(unsigned long long n) {
    bitset<bs_size> bs(n);
    const int bs_count = bs.count();
    string bs_str;
    while (bs.any()) {
        bs_str += to_string(bs[0]);
        bs >>= 1;
    }
    reverse(bs_str.begin(), bs_str.end());
    cout << bs_str << ' ' << bs_count << '\n';
}

int main() {

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    unsigned long long n;
    while (cin >> n) {
        if (n == 0)
            break;
        solve(n);
    }

    return 0;
}
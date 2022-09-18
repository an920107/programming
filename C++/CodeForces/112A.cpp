#include <bits/stdc++.h>
using namespace std;

int solve() {

    string str_a, str_b;
    cin >> str_a >> str_b;
    int l = str_a.length();
    for (int i = 0; i < l; ++ i) {
        if (str_a[i] >= 'a') str_a[i] -= 32;
        if (str_b[i] >= 'a') str_b[i] -= 32;
    }
    if (str_a > str_b) return 1;
    if (str_a < str_b) return -1;
    return 0;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << solve() << '\n';

    return 0;
}
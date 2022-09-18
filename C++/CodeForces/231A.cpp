#include <bits/stdc++.h>
using namespace std;

int main() {
    
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, c = 0, p[3];
    cin >> n;
    for (; n > 0; -- n) {
        cin >> p[0] >> p[1] >> p[2];
        c += p[0] + p[1] + p[2] > 1;
    }
    cout << c << '\n';

    return 0;
}
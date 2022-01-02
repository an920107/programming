#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0;
    int t; cin >> t;
    for (int i = 1; i <= t; i ++) {
        cin >> n;
        sum += n * i;
    }
    cout << sum << "\n";
    return 0;
}
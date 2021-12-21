#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, num = 1;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        num <<= 1;
        if (num >= 1000000007)
            num -= 1000000007;
    }
    cout << num << '\n';
    return 0;
}

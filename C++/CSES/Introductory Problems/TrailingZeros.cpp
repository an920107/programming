#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, count = 0;
    cin >> n;
    while (n > 0) {
        count += n / 5;
        n /= 5;
    }
    cout << count << '\n';
    return 0;
}

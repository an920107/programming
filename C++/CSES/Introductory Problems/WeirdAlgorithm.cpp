#include <bits/stdc++.h>

using namespace std;

void foo(long long);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    foo(n);
    return 0;
}

void foo(long long n) {
    if (n % 2 == 0) {
        cout << n << ' ';
        foo(n / 2);
    }
    else if (n != 1) {
        cout << n << ' ';
        foo(n * 3 + 1);
    }
    else {
        cout << n << '\n';
    }
}
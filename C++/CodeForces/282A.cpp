#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, sum = 0;
    string str;
    cin >> n;
    for (; n > 0; -- n) {
        cin >> str;
        sum += str[1] == '+' ? 1 : -1;
    }
    cout << sum << '\n';

    return 0;
}
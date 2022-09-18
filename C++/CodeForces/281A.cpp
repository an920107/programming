#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    if (str[0] >= 'a') str[0] -= 32;
    cout << str << '\n';

    return 0;
}
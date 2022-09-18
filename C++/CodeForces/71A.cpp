#include <bits/stdc++.h>
using namespace std;

int main() {
    
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l;
    string str;
    cin >> n;
    for (; n > 0; -- n) {
        cin >> str;
        l = str.length();
        if (l <= 10)
            cout << str << '\n';
        else
            cout << *str.begin() << l - 2 << *(str.end() - 1) << '\n';
    }

    return 0;
}
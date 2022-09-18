#include <bits/stdc++.h>
using namespace std;

int main() {

    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int w;
    cin >> w;
    cout << (w % 2 || w < 4 ? "NO\n" : "YES\n");

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    while (cin >> x >> y) {
        cout << ((x == y) ? x : y + 1) << "\n";
    }
    return 0;
}

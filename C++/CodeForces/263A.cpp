#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    bool b;
    int x, y;
    for (y = 1; y <= 5; ++ y) {
        for (x = 1; x <= 5; ++ x) {
            cin >> b;
            if (b) break;
        }
        if (b) break;
    }
    cout << abs(3 - x) + abs(3 - y) << '\n';
            
    return 0;
}
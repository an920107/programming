#include <iostream>

using namespace std;

int main() {
    int a, b, n;
    while (cin >> a >> b >> n) {
        cout << a / b << '.';
        a %= b;
        for (int i = 0; i < n; i++) {
            a *= 10;
            if (a / b == 0) cout << '0';
            else {
                cout << a / b;
                a %= b;
            }
        }
        cout << '\n';
    }
    return 0;
}

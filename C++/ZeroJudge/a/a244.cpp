#include <iostream>

using namespace std;

int main() {
    long n, a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        switch (a) {
        case 1:
            cout << b + c << '\n';
            break;
        case 2:
            cout << b - c << '\n';
            break;
        case 3:
            cout << b * c << '\n';
            break;
        case 4:
            cout << b / c << '\n';
            break;
        default:
            break;
        }
    }
    return 0;
}

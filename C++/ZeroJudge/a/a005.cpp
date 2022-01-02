#include <iostream>

using namespace std;

int main() {
    int t, a[5];
    for (cin >> t; t > 0; t--) {
        for (int i = 0; i < 4; i++)
            cin >> a[i];
        if (a[0] - a[1] == a[1] - a[2]) {
            a[4] = a[3] * 2 - a[2];
        }
        else {
            a[4] = a[3] * a[3] / a[2];
        }
        for (int j = 0; j < 5; j++)
            cout << a[j] << ' ';
        cout << '\n';
    }
    return 0;
}

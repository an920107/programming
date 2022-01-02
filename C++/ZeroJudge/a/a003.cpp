#include <iostream>

using namespace std;

int main() {
    int m, d, s;
    cin >> m >> d;
    s = (m * 2 + d) % 3;
    switch (s) {
    case 0:
        cout << "普通" << '\n';
        break;
    case 1:
        cout << "吉" << '\n';
        break;
    case 2:
        cout << "大吉" << '\n';
        break;
    }
    return 0;
}

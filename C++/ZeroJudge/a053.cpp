#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n >= 40) cout << "100";
        else if (n >= 21) cout << 80 + (n - 20);
        else if (n >= 11) cout << 60 + 2 * (n - 10);
        else cout << 6 * n;
        cout << '\n';
    }
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int input;
    while (cin >> input) {
        if (input == 0) break;
        for (int i = 1; i < input; i++) {
            if (i % 7 != 0) cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}

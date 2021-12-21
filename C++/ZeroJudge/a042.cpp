#include <iostream>

using namespace std;

int main() {
    long input;
    while (cin >> input) {
        cout << input * (input - 1) + 2 << endl;
        // n^2 - n + 2
    }
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int input;
    while (cin >> input) {
        cout << (input * input * input - input) / 6 + input + 1 << endl;
        // (n^3 - n) / 6 + n + 1
    }
    return 0;
}

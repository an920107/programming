#include <iostream>

using namespace std;

int main() {
    int input, digit;
    bool output[32];
    while (cin >> input) {
        digit = 0;
        for (int i = 0; input / 2 > 0; i++, digit++) {
            output[i] = bool(input % 2);
            input /= 2;
        }
        output[digit] = bool(input % 2);
        input /= 2;
        for (; digit >= 0; digit--) {
            cout << output[digit];
        }
        cout << '\n';
    }
    return 0;
}

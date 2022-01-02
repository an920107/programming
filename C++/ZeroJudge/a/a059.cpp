#include <iostream>

using namespace std;

int square(int);

int main() {
    int t, min, max, output;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        output = 0;
        cin >> min >> max;
        for (int i = min; i <= max; i++) {
            for (int base = 1; square(base) <= i; base++) {
                if (i == square(base)) output += i;
            }
        }
        cout << "Case " << c << ": " << output << '\n';
    }
    return 0;
}

int square(int input) {
    return input * input;
}
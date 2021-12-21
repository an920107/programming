#include <iostream>

using namespace std;

int main() {
    string input;
    int subtraction;
    while (cin >> input) {
        for (int i = 0; i < 6; i++) {
            subtraction = input[i] - input[i + 1];
            if (subtraction >= 0) cout << subtraction;
            else cout << -(subtraction);
        }
        cout << '\n';
    }
    return 0;
}

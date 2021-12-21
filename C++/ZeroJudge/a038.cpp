#include <iostream>

using namespace std;

int main() {
    string input;
    bool first_zero = true;
    cin >> input;
    for (int i = input.length() - 1; i >= 0; i--) {
        if (first_zero && input[i] == '0') continue;
        else first_zero = false;
        cout << input[i];
    }
    if (first_zero) cout << "0";
    return 0;
}

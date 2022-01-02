#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] != input[input.length() - i - 1]) {
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
    return 0;
}

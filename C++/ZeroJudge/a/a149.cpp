#include <iostream>

using namespace std;

int main() {
    int t;
    long output;
    string input;
    for (cin >> t; t > 0; t--) {
        cin >> input;
        output = 1;
        for (int i = 0; i < input.length(); i++) {
            output *= input[i] - 48;
        }
        cout << output << '\n';
    }
    return 0;
}

#include <iostream>

using namespace std;

unsigned int pow(int, int);

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    bool digits[32] = {0};
    unsigned int n, buffer, count;
    while (true) {
        cin >> n;
        if (n == 0) break;

        count = 0;
        for (int i = 0; i < 32; i++) {
            digits[i] = 0;
        }
        for (int i = 31; i >= 0; i--) {
            buffer = pow(2, i);
            if (n >= buffer) {
                n -= buffer;
                digits[i] = 1;
            }
        }
        for (int i = 0; i < 32; i++) {
            if (digits[i]) count++;
            else break;
        }
        cout << count << "\n";
    }
    return 0;
}

unsigned int pow(int base, int power) {
    if (power == 0) return 1;
    int output = 1;
    for (int i = 0; i < power; i++) {
        output *= base;
    }
    return output;
}
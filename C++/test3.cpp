#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, count = 0;
    cin >> n;
    while (n > 0) {
        int maxDigit = 0;
        for (char &ch : to_string(n)) {
            const int digit = ch - '0';
            if (digit > maxDigit)
                maxDigit = digit;
        }
        n -= maxDigit;
        count ++;
    }
    cout << count << '\n';
    return 0;
}
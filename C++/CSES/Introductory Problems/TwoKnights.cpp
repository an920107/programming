#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n, result = -8;
    cin >> n;
    for (long long i = 1; i <= n; i ++) {
        result += 2 * i * i * i - 3 * i * i - 7 * i + 16;
        cout << result << "\n";
    }
    return 0;
}
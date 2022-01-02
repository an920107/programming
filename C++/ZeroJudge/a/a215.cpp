#include <iostream>

using namespace std;

int main() {
    int min, max, count;
    long sum;
    while (cin >> min >> max) {
        count = 0;
        sum = 0;
        for (int i = min; ; i++) {
            sum += i;
            if (sum <= max) count++;
            else break;
        }
        cout << count + 1 << '\n';
    }
    return 0;
}

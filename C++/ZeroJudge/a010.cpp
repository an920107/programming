#include <iostream>

using namespace std;

int main() {
    int a, count;
    bool head = true;
    cin >> a;
    for (int d = 2; d <= a; d++) {
        count = 0;
        while (a % d == 0) {
            a /= d;
            count++;
        }
        if (count > 0) {
            if (head) head = false;
            else cout << " * ";
            if (count == 1) cout << d;
            else cout << d << '^' << count;
        }
    }
    return 0;
}

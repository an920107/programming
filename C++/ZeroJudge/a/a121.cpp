#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int min, max, count;
    bool flag;
    while (cin >> min >> max) {
        count = 0;
        if (min == 1 && max >= 1) min++;
        if (min == 2 && max >= 2) {
            count++;
            min++;
        }
        for (int i = min; i <= max; i++) {
            flag = false;
            for (int devide = 2; devide <= sqrt(i) + 1; devide++) {
                if (i % devide == 0) {
                    flag = true;
                    break;
                }
            }
            if (!flag) count++;
        }
        cout << count << '\n';
    }
    return 0;
}

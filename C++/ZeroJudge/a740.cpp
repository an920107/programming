#include <iostream>

using namespace std;

int main() {
    bool flag;
    int n, sum;
    while (scanf("%d", &n) != EOF) {
        flag = true;
        sum = 0;
        for (int i = 2; i < 44711; i ++) {
            while (n % i == 0) {
                n /= i;
                sum += i;
                flag = false;
            }
        }
        if (flag)
            sum = n;
        printf("%d\n", sum);
    }
    return 0;
}

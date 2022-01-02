#include <iostream>

using namespace std;

int main() {
    int num[2];
    while (scanf("%d %d", &num[0], &num[1]) != EOF) {
        while (num[0] != num[1]) {
            if (num[0] > num[1])
                num[0] -= num[1];
            else
                num[1] -= num[0];
        }
        printf("%d\n", num[0]);
    }
    return 0;
}

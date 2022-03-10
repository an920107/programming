#include <bits/stdc++.h>
using namespace std;

int sum2(int n) {
    if (n == 0) return 0;
    return 2 * n + sum2(n - 1);
}

int main() {
    const int n = 50;
    printf("sigma 2k as k=1..%d = %d\n", n, sum2(50));
    system("pause");
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

double rpower(double b, int n) {
    if (n == 0) return 1;
    return b * rpower(b, n - 1);
}

int main() {
    printf("(2.0)^3 is (%.1lf)\n", rpower(2.0, 3));
    system("pause");
    return 0;
}

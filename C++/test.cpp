#include <bits/stdc++.h>
using namespace std;

void recursion(long long a, long long b) {
    if (a < 0) return;
    recursion(b, a + b);
}

void loop(long long a, long long b) {
    while (a > 0) {
        b += a;
        a = b - a;
    }
}

int main() {
    clock_t start, end;
    start = clock();
    for (int i = 0; i < 10000000; ++ i)
        recursion(1, 1);
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    start = clock();
    for (int i = 0; i < 10000000; ++ i)
        loop(1, 1);
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    return 0;
}
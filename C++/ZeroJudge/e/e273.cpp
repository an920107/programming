#include <bits/stdc++.h>
using namespace std;

int getint() {
    int res = 0;
    char tmp = '0';
    while (tmp >= '0' && tmp <= '9') {
        res = (res << 3) + (res << 1) + tmp - '0';
        tmp = getchar();
    }
    return res;
}

void putint(int num) {
    if (num == 0) putchar('0');
    char tmp[10];
    int len = 0;
    while (num > 0) {
        tmp[len ++] = num % 10 + '0';
        num /= 10;
    }
    while (len > 0) {
        putchar(tmp[-- len]);
    }
}

void solve(int n) {
    int arr[1000];
    for (int i = 0; i < n; i ++) {
        arr[n - i - 1] = getint();
    }
    if (n == 1) {
        putchar('0');
        putchar('\n');
        return;
    }
    for (int i = n - 1; i > 0; i --) {
        putint(arr[i] * i);
        putchar(' ');
    }
    putchar('\n');
}

int main() {
    int n;
    while (n = getint()) {
        solve(n);
    }
    return 0;
}
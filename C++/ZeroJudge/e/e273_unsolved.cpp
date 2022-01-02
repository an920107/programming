#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    int arr[1000];
    for (int i = 0; i < n; i ++) {
        scanf("%d", &arr[n - i - 1]);
    }
    if (n == 1) {
        printf("0\n");
        return;
    }
    for (int i = n - 1; i > 0; i --) {
        printf("%d ", arr[i] * i);
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        solve(n);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE

int main() {
    int n, x, sum = 0;
    long long arr[200000];
    cin >> n >> x;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = n - 1, j = 0; i >= j; i --) {
        if (arr[i] + arr[j] <= x) {
            j ++;
        }
        sum ++;
    }
    cout << sum << "\n";
    return 0;
}

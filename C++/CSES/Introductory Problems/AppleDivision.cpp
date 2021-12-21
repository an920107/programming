#include <bits/stdc++.h>
using namespace std;

int DFS(int, long long*, long long, int);

int main() {
    int n;
    long long arr[20], sum = 0;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << DFS(0, arr, sum, n);
    return 0;
}

int DFS(int i, long long* arr, long long sum, int n) {
    static long long min_diff = 1E17;
    if (i < n - 1) {
        DFS(i + 1, arr, sum - arr[i] * 2, n);
    }
    if (i < n - 1) {
        DFS(i + 1, arr, sum, n);
    }
    if (i == n - 1) {
        min_diff = min(min_diff, abs(sum));
    }
    return min_diff;
}

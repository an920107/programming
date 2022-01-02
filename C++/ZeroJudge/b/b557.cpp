#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, arr[100], count = 0;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        arr[i] *= arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            for (int k = n - 1; k > j; k --) {
                if (arr[i] + arr[j] == arr[k]) count ++;
                else if (arr[i] + arr[j] > arr[k]) break;
            }
        }
    }
    return count;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i ++) {
        cout << solve() << "\n";
    }
    return 0;
}
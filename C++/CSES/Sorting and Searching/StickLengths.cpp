#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, arr[200000];
    cin >> n;
    for (int i = 0 ; i < n; i ++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long mid = arr[n / 2], sum = 0;
    for (int i = 0; i < n; i ++) {
        sum += abs(mid - arr[i]);
    }
    cout << sum << "\n";
    return 0;
}
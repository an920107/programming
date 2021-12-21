#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[200000], n, result;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    result = n;
    for (int i = 1; i < n; i ++) {
        result -= arr[i] == arr[i - 1];
    }
    cout << result << "\n";
    return 0;
}

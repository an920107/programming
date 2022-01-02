#include <bits/stdc++.h>
using namespace std;

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main() {
    int n, count = 0;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i ++) {
        for (int j = n - 1; j > i; j --) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                count ++;
            }
        }
    }
    cout << count << "\n";
    return 0;
}
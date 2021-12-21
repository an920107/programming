#include <bits/stdc++.h>
using namespace std;

int arr[1000000];

int main() {
    long long n, sum, arr_count = 0, arr_sum = 0;
    cin >> n;
    sum = n * (n + 1) / 2;
    if (sum % 2 == 0) {
        cout << "YES\n";
        sum /= 2;
        for (int i = n; i >= 1; i --) {
            if (arr_sum + i <= sum) {
                arr[arr_count] = i;
                arr_sum += i;
                arr_count ++;
                if (arr_sum == sum)
                    break;
            }
        }
        cout << arr_count << '\n';
        for (int i = 0; i < arr_count; i ++)
            cout << arr[i] << ' ';
        cout << '\n' << n - arr_count << '\n';
        for (int i = n, loc = 0; i >= 1; i --) {
            if (i != arr[loc])
                cout << i << ' ';
            else loc ++;
        }
        cout << '\n';
    }
    else cout << "NO\n";
    return 0;
}

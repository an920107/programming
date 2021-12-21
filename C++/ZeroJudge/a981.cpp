#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int n, m, sum, tmp, arr[30], pow_list[30];
    vector<int> output;
    for (int i = 0; i < 30; i ++)
        pow_list[i] = pow(2, i);
    while (cin >> n >> m) {
        for (int i = 0; i < n; i ++)
            cin >> arr[i];
        sort(arr, arr + n);
        for (int count = 1; count <= pow(2, n); count ++) {
            sum = 0;
            tmp = count;
            output.clear();
            for (int i = n - 1; i >= 0; i --) {
                if (tmp >= pow_list[i]) {
                    tmp -= pow_list[i];
                    sum += arr[i];
                    output.push_back(arr[i]);
                }
            }
            if (sum == m) {
                for (int i = output.size() - 1; i > 0; i --)
                    cout << output[i] << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}

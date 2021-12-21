#include <bits/stdc++.h>

using namespace std;

long long arr[200000], sum[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q, begin, end;
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> arr[i];
    sum[0] = 0;
    for (int i = 1; i <= n; i ++)
        sum[i] = sum[i - 1] + arr[i - 1];
    cin >> q;
    for (; q > 0; q --) {
        cin >> begin >> end;
        cout << sum[end] - sum[begin - 1] << '\n';
    }
    return 0;
}

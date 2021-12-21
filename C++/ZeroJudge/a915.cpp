#include <bits/stdc++.h>

using namespace std;

void SwapPair(int, int);
pair<int, int> num[1000];
pair<int, int> pair_tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, same_begin, same_end;
    while (cin >> n) {
        same_begin = -1;
        for (int i = 0; i < n; i ++)
            cin >> num[i].first >> num[i].second;
        for (int j = n - 1; j > 0; j --)
            for (int i = 0; i < j; i ++)
                if (num[i].first > num[i + 1].first)
                    SwapPair(i, i + 1);
        for (int j = n - 1; j > 0; j --)
            for (int i = 0; i < j; i ++)
                if (num[i].first == num[i + 1].first)
                    if (num[i].second > num[i + 1].second)
                        SwapPair(i, i + 1);
        for (int i = 0; i < n; i ++)
            cout << num[i].first << ' ' << num[i].second << '\n';
    }
    return 0;
}

void SwapPair(int n, int m) {
    pair_tmp = num[n];
    num[n] = num[m];
    num[m] = pair_tmp;
}
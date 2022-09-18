#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, score, res = 0;
    vector<int> vec;
    cin >> n >> k;
    for (int i = 0 ; i < n; ++ i) {
        cin >> score;
        vec.emplace_back(score);
    }
    k = vec[k - 1];
    for (auto &x : vec) {
        res += x && x >= k;
    }
    cout << res << '\n';

    return 0;
}
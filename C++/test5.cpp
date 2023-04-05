#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &vec) {

    vector<vector<int>> dp(vec.size() + 1, vector<int>(vec.size() + 1));
    
}

int main() {

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i ++)
        cin >> vec[n];
    solve(vec);

    return 0;
}

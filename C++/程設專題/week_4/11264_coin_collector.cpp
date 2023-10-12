#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &coins) {
    stack<int> hold;
    int sum = 0;
    for (auto coin : coins) {
        if (sum > coin) {
            sum -= hold.top();
            hold.pop();
        }
        hold.emplace(coin);
        sum += coin;
    }
    return hold.size();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int count;
        cin >> count;
        vector<int> coins(count);
        for (int i = 0; i < count; i++) cin >> coins[i];
        cout << solve(coins) << "\n";
    }
    return 0;
}
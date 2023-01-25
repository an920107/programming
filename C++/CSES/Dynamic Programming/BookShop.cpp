#include <bits/stdc++.h>
using namespace std;

const int MAX_PRICE = 1E5;

class Solve {
private:

    int budget; // 預算
    vector<int> dp; // dp[i]: 價錢 i 時買得到的頁數，初始化為 0
    vector<pair<int, int>> books; // [price, page]

public:

    Solve(int _budget, vector<pair<int, int>> &_books) :
        budget(_budget), dp(MAX_PRICE + 1, 0), books(_books) {}

    int run() {
        // g++: -std=c++17
        // vscode: cppstandard = 17
        for (auto &[price, page] : books)
            // 從後面往前避免重複計算
            for (int i = MAX_PRICE; i >= price; i --)
                // 取 新的可能 與 原本的 較大者
                dp[i] = max(dp[i - price] + page, dp[i]);

        // 從 budget 開始找，找到第一個頁數 > 0
        for (int i = budget; i >= 0; i --)
            if (dp[i] > 0)
                return dp[i];
    }
};

int main() {

    int n, budget;
    cin >> n >> budget;
    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; i ++)
        cin >> books[i].first;
    for (int i = 0; i < n; i ++)
        cin >> books[i].second;
    
    Solve sol(budget, books);
    cout << sol.run() << '\n';

    return 0;
}
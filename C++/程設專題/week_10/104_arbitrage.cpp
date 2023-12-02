#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<vector<double>> &table) {
    auto n = table.size();
    vector<vector<vector<double>>> dp(
        n, vector<vector<double>>(n, vector<double>(n)));
    vector<vector<vector<int>>> path(
        n, vector<vector<int>>(n, vector<int>(n, -1)));

    // dp[t][i][j] 表示從 (i 貨幣) 經過 t 次轉換為 (j 貨幣) 的最佳匯率
    // path[t][i][j] 紀錄 dp[t - 1][i][k] 與 dp[t][k][j] 的 k

    // table 本身就是第一次轉換的結果，所以 dp[0] 相當於 table
    dp[0] = table;

    // dp[t][i][j] = max(
    //     dp[t - 1][i][0] * table[0][j],
    //     dp[t - 1][i][1] * table[1][j],
    //     ......,
    //     dp[t - 1][i][n - 1] * table[n - 1][j]
    // )
    auto find_best = [&]() -> pair<int, int> {
        for (int t = 1; t < n; t++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    double max_rate = -INFINITY;
                    for (int k = 0; k < n; k++) {
                        double new_rate = dp[t - 1][i][k] * table[k][j];
                        if (new_rate > max_rate) {
                            max_rate = new_rate;
                            path[t][i][j] = k;
                        }
                    }
                    dp[t][i][j] = max_rate;
                }
                // 找到匯率大於 1.01
                if (dp[t][i][i] > 1.01) return make_pair(i, t);
            }
        }
        // 找不到
        return make_pair(-1, -1);
    };
    auto best_pair = find_best();
    int best_i = best_pair.first, best_t = best_pair.second;

    // 找路徑
    vector<int> result;
    function<void(int, int, int)> find_path = [&](int t, int i, int j) {
        if (t < 0) return;
        if (t == 0) {
            result.emplace_back(i + 1);
            result.emplace_back(j + 1);
            return;
        }
        find_path(t - 1, i, path[t][i][j]);
        result.emplace_back(j + 1);
    };
    find_path(best_t, best_i, best_i);
    return result;
}

int main() {
    int n;
    while (cin >> n) {
        vector<vector<double>> table(n, vector<double>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i == j)
                    table[i][j] = 1;
                else
                    cin >> table[i][j];
        auto result = solve(table);
        if (result.empty())
            cout << "no arbitrage sequence exists\n";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << (i < result.size() - 1 ? " " : "\n");
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> directions({
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
});

bool cmp(pair<char, int> &x, pair<char, int> &y) {
    if (x.second > y.second)
        return true;
    else if (x.second == y.second)
        if (x.first < y.first)
            return true;
    return false;
}

void solve(int h, int w, vector<vector<char>> &graph) {
    vector<vector<bool>> visited(h, vector<bool>(w));
    function<void(int, int, char)> dfs = [&](int i, int j, char c) {
        if (i < 0 || j < 0 || i >= h || j >= w)
            return;
        if (visited[i][j])
            return;
        if (graph[i][j] != c)
            return;
        
        visited[i][j] = true;
        for (auto &[di, dj] : directions)
            dfs(i + di, j + dj, c);
    };

    map<char, int> result;
    for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j ++) {
            if (!visited[i][j]) {
                dfs(i, j, graph[i][j]);
                result[graph[i][j]] ++;
            }
        }
    }

    vector<pair<char, int>> ordered_result;
    for (auto &[c, v] : result)
        ordered_result.emplace_back(c, v);
    sort(ordered_result.begin(), ordered_result.end(), cmp);
    for (auto &[c, v] : ordered_result)
        cout << c << ": " << v << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, h, w;
    cin >> n;
    for (int t = 1; t <= n; t ++) {
        cin >> h >> w;
        vector<vector<char>> graph(h, vector<char>(w));
        for (int i = 0; i < h; i ++) {
            for (int j = 0; j < w; j ++) {
                cin >> graph[i][j];
            }
        }
        cout << "World #" << t << '\n';
        solve(h, w, graph);
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int solve(int max_node, vector<pair<int, int>> &edges) {
    vector<vector<int>> graph(max_node + 1);
    for (auto &p : edges) {
        graph[p.first].emplace_back(p.second);
        graph[p.second].emplace_back(p.first);
    }

    vector<bool> visited(max_node, false);
    int result = 0;
    function<void(int)> dfs = [&](int point) {
        if (visited[point]) return;
        visited[point] = true;
        for (auto x : graph[point])
            dfs(x);
    };
    for (int i = 0; i < max_node; i++) {
        if (!visited[i]) {
            result++;
            dfs(i);
        }
    }

    return result;
}

int main() {
    int count;
    cin >> count;
    string input;
    getline(cin, input);
    getline(cin, input);
    while (count--) {
        getline(cin, input);
        char max_node = input[0];
        vector<pair<int, int>> edges;
        while (getline(cin, input)) {
            if (input == "") break;
            edges.emplace_back(make_pair(input[0] - 'A', input[1] - 'A'));
        }
        cout << solve(max_node - 'A', edges) << "\n";
    }
    return 0;
}
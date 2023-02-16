#include <bits/stdc++.h>
using namespace std;

void solve(int citiesCount, const vector<pair<int, int>>& roads) {

    vector<vector<int>> adjacencyList(citiesCount + 1);
    vector<int> visited(citiesCount + 1, -1);
    int resultPoint = -1, resultRoot = -1;

    for (auto &[u, v] : roads) {
        adjacencyList[u].emplace_back(v);
        adjacencyList[v].emplace_back(u);
    }

    function<void(int)> dfs = [&](int root) -> void {
        for (auto &point : adjacencyList[root]) {
            if (visited[point] >= 0 && point != visited[root]) {
                resultPoint = point;
                resultRoot = root;
                return;
            }
            if (visited[point] < 0 && resultPoint < 0) {
                visited[point] = root;
                dfs(point);
            }
        }
    };

    for (int i = 1; i <= citiesCount; i ++)
        if (visited[i] < 0 && resultPoint < 0) {
            visited[i] = i;
            dfs(i);
        }

    if (resultPoint < 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> resultPath;
    int current = resultPoint;
    while (current != resultRoot) {
        resultPath.emplace_back(current);
        current = visited[current];
    }

    cout << resultPath.size() + 2 << '\n';
    cout << current << ' ';
    for (auto &point : resultPath)
        cout << point << ' ';
    cout << current << '\n';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int citiesCount, roadsCount;
    cin >> citiesCount >> roadsCount;

    vector<pair<int, int>> roads(roadsCount);
    for (int i = 0; i < roadsCount; i ++)
        cin >> roads[i].first >> roads[i].second;

    solve(citiesCount, roads);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solve {
private:

    vector<pair<int, int>> existedRoads;
    vector<vector<int>> adjacencyList;
    int existedRoadsCount, cityRange;

public:

    Solve(int _cityRange, const vector<pair<int, int>> &_existedRoads)
    : existedRoads(_existedRoads), cityRange(_cityRange) {

        existedRoadsCount = existedRoads.size();

        adjacencyList = vector<vector<int>>(cityRange + 1);
        for (auto &[x, y] : existedRoads) {
            adjacencyList[x].emplace_back(y);
            adjacencyList[y].emplace_back(x);
        }
    }

    void run() {

        vector<int> blockLeader;
        vector<bool> visited(cityRange + 1);

        function<void(int)> dfs = [&](int root) -> void {
            visited[root] = true;
            for (auto &city : adjacencyList[root])
                if (!visited[city])
                    dfs(city);
        };

        for (int city = 1; city <= cityRange; city ++) {
            if (visited[city])
                continue;

            blockLeader.emplace_back(city);
            dfs(city);
        }

        const int blockCount = blockLeader.size();
        cout << blockCount - 1 << '\n';
        for (int i = 1; i < blockCount; i ++)
            cout << blockLeader[i - 1] << ' ' << blockLeader[i] << '\n';
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cityRange, roadCount;
    cin >> cityRange >> roadCount;

    vector<pair<int, int>> existedRoads(roadCount);
    for (int i = 0; i < roadCount; i ++)
        cin >> existedRoads[i].first >> existedRoads[i].second;
    
    Solve sol(cityRange, existedRoads);
    sol.run();

    return 0;
}
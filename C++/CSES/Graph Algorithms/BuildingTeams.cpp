#include <bits/stdc++.h>
using namespace std;

class Solve {
private:

    class Graph {
    private:

        int size;
        vector<vector<int>> adjacencyList;

        // 0: 未參訪過; 1: 第一組; 2: 第二組
        vector<int> teamList;

        bool available = true;

    public:

        Graph(int _size)
            : size(_size), adjacencyList(_size + 1), teamList(_size + 1) {}

        inline const int& getSize() { return size; }
        inline const vector<int>& getTeamList() { return teamList; }
        inline const bool& getAvailable() { return available; }

        void addEdge(int u, int v) {
            adjacencyList[u].emplace_back(v);
            adjacencyList[v].emplace_back(u);
        }

        void dfs(int root, int teamToAdd) {

            if (!available)
                return;

            teamList[root] = teamToAdd;
            
            for (auto &point : adjacencyList[root]) {
                if (teamList[point] == teamToAdd)
                    available = false;
                else if (teamList[point] == 0)
                    dfs(point, (teamToAdd == 1) ? 2 : 1);
            }
        }
    };

    Graph graph;
    vector<pair<int, int>> edges;

public:

    Solve(int _maxNum, vector<pair<int, int>> &_edges)
        : graph(_maxNum), edges(_edges) {}

    void run() {
        for (auto &[u, v] : edges)
            graph.addEdge(u, v);
        
        for (int i = 1; i <= graph.getSize(); i ++)
            if (graph.getTeamList()[i] == 0)
                graph.dfs(i, 1);

        if (graph.getAvailable())
            for (int i = 1; i <= graph.getSize(); i ++)
                cout << graph.getTeamList()[i] << ' ';
        else cout << "IMPOSSIBLE";
        cout << '\n';
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int maxNum, edgeCount;
    cin >> maxNum >> edgeCount;

    vector<pair<int, int>> edges(edgeCount);
    for (int i = 0; i < edgeCount; i ++)
        cin >> edges[i].first >> edges[i].second;

    Solve sol(maxNum, edges);
    sol.run();

    return 0;
}
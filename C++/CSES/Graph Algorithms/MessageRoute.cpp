#include <bits/stdc++.h>
using namespace std;

class Solve {
protected:

    class Graph {
    private:

        struct Node {
            int key;
            Node *parent;

            Node(int _key, Node *_parent)
                : key(_key), parent(_parent) {}
        };

        int size;
        vector<vector<int>> adjacencyList;

    public:

        Graph(int _size)
        : size(_size), adjacencyList(_size + 1) {}

        inline int getSize() {
            return size;
        }

        void addEdge(int u, int v) {
            adjacencyList[u].emplace_back(v);
            adjacencyList[v].emplace_back(u);
        }

        /// @brief 以 BFS 尋找起點到終點的最短路徑
        /// @param start 起點
        /// @param end 終點
        /// @return 最短的路徑
        vector<int> bfs(int start, int end) {

            vector<bool> visited(size + 1);
            queue<Node> que;
            Node *current;

            que.emplace(start, nullptr);
            while (!que.empty()) {
                current = new Node(que.front());
                if (current->key == end)
                    break;
                que.pop();

                for (auto &point : adjacencyList[current->key])
                    if (!visited[point]) {
                        visited[point] = true;
                        que.emplace(point, current);
                    }
            }

            if (que.empty())
                return vector<int>();

            vector<int> result;
            result.emplace_back(current->key);
            while (current->parent != nullptr) {
                current = current->parent;
                result.emplace_back(current->key);
            }
            reverse(result.begin(), result.end());

            return result;
        }
    };

private:
    
    vector<pair<int, int>> connections;
    Graph graph;

public:

    Solve(int _computerCount, const vector<pair<int, int>> &_connections)
    : connections(_connections), graph(_computerCount) {}

    void run() {

        for (auto &[u, v] : connections)
            graph.addEdge(u, v);
        
        auto resultPath = graph.bfs(1, graph.getSize());

        if (!resultPath.empty()) {
            cout << resultPath.size() << '\n';
            for (auto &point : resultPath)
                cout << point << ' ';
            cout << '\n';
        }
        else cout << "IMPOSSIBLE\n";
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int computerCount, connectionCount;
    cin >> computerCount >> connectionCount;

    vector<pair<int, int>> connections(connectionCount);
    for (int i = 0; i < connectionCount; i ++)
        cin >> connections[i].first >> connections[i].second;

    Solve sol(computerCount, connections);
    sol.run();

    return 0;
}
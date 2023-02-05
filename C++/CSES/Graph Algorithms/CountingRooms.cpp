#include <bits/stdc++.h>
using namespace std;

class Solve {
protected:

    const vector<pair<int, int>> DIRECTIONS =
        {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    struct Point {
        int row, col;

        Point() {}
        Point(int _row, int _col) : row(_row), col(_col) {}
    };

private:

    vector<vector<char>> roomMap;
    int m, n;

public:

    Solve(vector<vector<char>> &_roomMap)
    : roomMap(_roomMap) {

        m = roomMap.size();
        n = roomMap[0].size();
    }

    int run() {

        vector<vector<bool>> visited(m, vector<bool>(n));
        int count = 0;

        // bfs lambda
        auto bfs = [&](const Point &point) {
            queue<Point> que;
            que.push(point);

            while (!que.empty()) {
                Point curr = que.front();
                que.pop();
                if (visited[curr.row][curr.col])
                    continue;

                visited[curr.row][curr.col] = true;
                for (auto &[dx, dy] : DIRECTIONS)
                    if (roomMap[curr.row + dx][curr.col + dy] != '#')
                        que.emplace(curr.row + dx, curr.col + dy);
            }
        };

        // for all point
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < n; j ++)
                if (roomMap[i][j] != '#' && !visited[i][j]) {
                    bfs(Point(i, j));
                    count ++;
                }
        
        return count;
    }

};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    // 多加外面一圈邊界 '#'
    vector<vector<char>> roomMap(m + 2, vector<char>(n + 2, '#'));
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> roomMap[i][j];
    
    Solve sol(roomMap);
    cout << sol.run() << '\n';

    return 0;
}
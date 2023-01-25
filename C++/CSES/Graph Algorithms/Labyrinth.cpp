#include <bits/stdc++.h>
using namespace std;

class Solve {
protected:

    const vector<pair<int, int>> DIRECTIONS =
        {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    struct Point {
        int row, col;
        Point *parent;

        Point() {}
        Point(int _row, int _col)
            : row(_row), col(_col), parent(nullptr) {}
        Point(int _row, int _col, Point *_parent)
            : row(_row), col(_col), parent(_parent) {}

        inline bool operator==(const Point &x) {
            return this->row == x.row && this->col == x.col;
        }

        char directionFrom(const Point &x) {
            if (this->row > x.row)
                return 'D';
            if (this->row < x.row)
                return 'U';
            if (this->col > x.col)
                return 'R';
            // if (this->col < x.col)
                return 'L';
        }
    };

private:

    int m, n;
    vector<vector<char>> labMap;
    Point startPoint, endPoint;

    Point findCharacter(char x) {
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < n; j ++)
                if (labMap[i][j] == x)
                    return Point(i, j);
        return Point(-1, -1);
    }

public:

    Solve(vector<vector<char>> &_labMap)
    : labMap(_labMap) {
        
        m = labMap.size();
        n = labMap[0].size();

        startPoint = findCharacter('A');
        endPoint = findCharacter('B');
    }

    void run() {
        queue<Point> bfs;
        vector<vector<bool>> visited(m, vector<bool>(n));

        bfs.push(startPoint);
        while (!bfs.empty()) {
            Point *curr = new Point(bfs.front());
            if (*curr == endPoint)
                break;
            bfs.pop();

            if (visited[curr->row][curr->col])
                continue;

            visited[curr->row][curr->col] = true;

            for (auto &[dx, dy] : DIRECTIONS)
                if (labMap[curr->row + dx][curr->col + dy] != '#')
                    bfs.emplace(curr->row + dx, curr->col + dy, curr);
        }

        if (bfs.empty())
            cout << "NO\n";
        else {
            cout << "YES\n";

            int step = 0;
            string path;
            Point *lookback = new Point(bfs.front());

            while (lookback->parent != nullptr) {
                step ++;
                path.push_back(lookback->directionFrom(*lookback->parent));
                lookback = lookback->parent;
            }
            reverse(path.begin(), path.end());

            cout << step << '\n';
            cout << path << '\n';
        }
    
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    // 多加外面一圈邊界 '#'
    vector<vector<char>> labMap(m + 2, vector<char>(n + 2, '#'));
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> labMap[i][j];

    Solve sol(labMap);
    sol.run();

    return 0;
}
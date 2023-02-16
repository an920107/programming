#include <bits/stdc++.h>
using namespace std;

class DSU {
private:

    vector<int> root;
    int maxBlockSize = 1, blockCount;

public:

    DSU(int _size) : root(_size, -1), blockCount(_size) {}

    inline const int& MaxBlockSize() { return maxBlockSize; }
    inline const int& BlockCount() { return blockCount; }

    int Find(int node) {
        if (root[node] < 0)
            return node;
        root[node] = Find(root[node]);
        return root[node];
    }

    void Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        // if (x > y)
        //     swap(x, y);
        if (x != y) {
            root[x] += root[y];
            root[y] = x;
            blockCount --;
            if (-root[x] > maxBlockSize)
                maxBlockSize = -root[x];
        }
    }
};

void solve(int cityCount, const vector<pair<int, int>>& roads) {

    DSU dsu(cityCount + 1);

    for (auto &[u, v] : roads) {
        dsu.Union(u, v);
        cout << dsu.BlockCount() - 1 << ' '
            << dsu.MaxBlockSize() << '\n';
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cityCount, roadCount;
    cin >> cityCount >> roadCount;

    vector<pair<int, int>> roads(roadCount);
    for (int i = 0; i < roadCount; i ++)
        cin >> roads[i].first >> roads[i].second;
    
    solve(cityCount, roads);

    return 0;
}
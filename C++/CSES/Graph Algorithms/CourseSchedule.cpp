#include <bits/stdc++.h>
using namespace std;

void solve(int courseCount, const vector<pair<int, int>>& requirements) {

    vector<vector<int>> adjacencyList(courseCount + 1);
    vector<int> priority(courseCount + 1);
    vector<bool> visited(courseCount + 1);
    vector<int> result;

    for (auto &[u, v] : requirements) {
        adjacencyList[u].emplace_back(v);
        priority[v] ++;
    }

    queue<int> bfsQueue;
    for (int i = 1; i <= courseCount; i ++)
        if (priority[i] == 0)
            bfsQueue.emplace(i);
    
    while (!bfsQueue.empty()) {
        int current = bfsQueue.front();
        bfsQueue.pop();
        visited[current] = true;
        result.emplace_back(current);
        for (auto &nextNode : adjacencyList[current]) {
            priority[nextNode] --;
            if (priority[nextNode] == 0 && !visited[nextNode])
                bfsQueue.emplace(nextNode);
        }
    }

    if (result.size() == courseCount)
        for (auto &course : result)
            cout << course << ' ';
    else cout << "IMPOSSIBLE";
    cout << '\n';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int courseCount, requirementCount;
    cin >> courseCount >> requirementCount;

    vector<pair<int, int>> requirements(requirementCount);
    for (int i = 0; i < requirementCount; i ++)
        cin >> requirements[i].first >> requirements[i].second;

    solve(courseCount, requirements);

    return 0;
}
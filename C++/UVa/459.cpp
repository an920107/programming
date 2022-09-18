#include <bits/stdc++.h>
using namespace std;

void dfs(int start, int range, vector<int> graph[26], bool visited[26]) {

    visited[start] = true;
    auto iter = graph[start].begin();
    auto iterEnd = graph[start].end();

    while (true) {
        if (!visited[*iter])
            dfs(*iter, range, graph, visited);
        if ((++ iter) == iterEnd)
            break;
    }
}

void solve(const int &t) {

    string str;
    vector<int> graph[26];
    int result = 0;
    bool visited[26]{false};

    getline(cin, str);
    int maxChar = str[0] - 'A';
    for (int i = 0; i <= maxChar; i ++)
        graph[i].emplace_back(i);
    while (getline(cin, str)) {
        if (str == "") break;
        pair<int, int> pr{str[0] - 'A', str[1] - 'A'};
        graph[pr.first].emplace_back(pr.second);
        graph[pr.second].emplace_back(pr.first);
    }
    for (int i = 0; i <= maxChar; i ++) {
        if (!visited[i]) {
            result ++;
            dfs(i, maxChar, graph, visited);
        }
    }

    cout << result << (t > 0 ? "\n\n" : "\n");
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    int t;
    
    cin >> t;
    getline(cin, str);
    getline(cin, str);
    while (t --) {
        solve(t);
    }

    return 0;
}

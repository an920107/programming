#include <bits/stdc++.h>
using namespace std;

vector<int> graph[26];
bool visited[26];

void dfs(const int &start) {

    visited[start] = true;
    for (int point : graph[start])
        if (!visited[point])
            dfs(point);
}

void solve(const int &t) {

    string str;
    int result = 0;

    getline(cin, str);
    int maxChar = str[0] - 'A';
    while (getline(cin, str)) {
        if (str == "") break;
        const int u = str[0] - 'A', v = str[1] - 'A';
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    for (int i = 0; i <= maxChar; i ++) {
        if (!visited[i]) {
            result ++;
            dfs(i);
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

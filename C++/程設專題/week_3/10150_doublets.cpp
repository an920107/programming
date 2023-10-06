#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solve(unordered_set<string> &dictionary,
                             vector<pair<string, string>> &query) {
    unordered_map<string, unordered_set<string>> graph;
    for (auto &word : dictionary) {
        for (int i = 0; i < word.length(); i++) {
            string adjacent = word;
            for (char c = 'a'; c <= 'z'; c++) {
                if (word[i] == c) continue;
                adjacent[i] = c;
                if (dictionary.find(adjacent) != dictionary.end()) {
                    graph[word].insert(adjacent);
                    graph[adjacent].insert(word);
                }
            }
        }
    }
    vector<vector<string>> result;
    for (auto &p : query) {
        string from = p.second, dest = p.first;
        result.emplace_back();

        bool found = false;
        unordered_map<string, string> ancestor;
        unordered_set<string> visited;
        queue<string> bfs_queue;
        bfs_queue.push(from);
        visited.insert(from);
        while (!bfs_queue.empty()) {
            string current = bfs_queue.front();
            bfs_queue.pop();
            if (current == dest) {
                found = true;
                break;
            }
            for (auto &next : graph[current]) {
                if (visited.find(next) == visited.end()) {
                    bfs_queue.push(next);
                    visited.insert(next);
                    ancestor[next] = current;
                }
            }
        }
        if (found) {
            string current = dest;
            while (true) {
                result.back().push_back(current);
                if (current == from) break;
                current = ancestor[current];
            }
        }
    }
    return result;
}

int main() {
    unordered_set<string> dictionary;
    string line;
    while (getline(cin, line)) {
        if (line == "") break;
        dictionary.insert(line);
    }
    vector<pair<string, string>> query;
    while (getline(cin, line)) {
        if (line == "") break;
        query.emplace_back();
        stringstream ss(line);
        ss >> query.back().first >> query.back().second;
    }
    auto results = solve(dictionary, query);
    for (int i = 0; i < results.size(); i++) {
        if (results[i].empty())
            cout << "No solution.\n";
        else
            for (auto &word : results[i]) cout << word << "\n";

        if (i < results.size() - 1) cout << "\n";
    }

    return 0;
}

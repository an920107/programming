#include <bits/stdc++.h>
using namespace std;

#define ERDOS_NAME "Erdos, P."

vector<string> split(string &str, const regex &reg, const char *make_up) {
    regex_token_iterator<string::iterator> it(str.begin(), str.end(), reg, -1), end;
    vector<string> result;
    while (it != end) {
        string token = *it;
        result.emplace_back(token + make_up);
        it++;
    }
    return result;
}

void modify_graph(unordered_map<string, vector<string>> &graph, const vector<string> &nodes) {
    for (int head = 0; head < nodes.size(); head++)
        for (int i = 0; i < nodes.size(); i++)
            if (head != i)
                graph[nodes[head]].emplace_back(nodes[i]);
}


vector<pair<string, int>> solve(vector<string> &papers, const vector<string> &names) {
    static regex reg("\\., |\\.:.*");
    unordered_map<string, vector<string>> graph;
    for (auto &paper : papers) {
        auto names_in_paper = split(paper, reg, ".");
        modify_graph(graph, names_in_paper);
    }

    unordered_map<string, int> distance;
    // <name, layer>
    queue<pair<string, int>> bfs_queue;
    distance[ERDOS_NAME] = -1;
    bfs_queue.emplace(ERDOS_NAME, 0);
    while (!bfs_queue.empty()) {
        string author = bfs_queue.front().first;
        int layer = bfs_queue.front().second;
        bfs_queue.pop();
        for (auto &collaborator : graph[author]) {
            if (distance[collaborator] == 0) {
                bfs_queue.emplace(collaborator, layer + 1);
                distance[collaborator] = layer + 1;
            }
        }
    }

    vector<pair<string, int>> result;
    for (auto &name : names)
        result.emplace_back(name, distance[name]);
    return result;
}

int main() {
    int t;
    cin >> t;
    for (int case_count = 1; case_count <= t; case_count++) {
        int papers_number, names_number;
        cin >> papers_number >> names_number;
        vector<string> papers, names;
        cin.ignore();
        for (int i = 0; i < papers_number; i++) {
            papers.emplace_back();
            getline(cin, papers.back());
        }
        for (int i = 0; i < names_number; i++) {
            names.emplace_back();
            getline(cin, names.back());
        }

        cout << "Scenario " << case_count << "\n";
        for (auto &p : solve(papers, names))
            cout << p.first << " "
                 << (p.second ? to_string(p.second) : "infinity") << "\n";
    }
    return 0;
}
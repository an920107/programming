#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int candidate_count, vector<queue<int>> votes) {
    vector<int> votes_got(candidate_count);
    int total_votes_count = 0;
    for (auto &q : votes)
        if (!q.empty()) {
            votes_got[q.front()]++;
            total_votes_count++;
        }
    while (true) {
        vector<int> max_votes_candidates, min_votes_candidates;
        int max_votes_count = 0, min_votes_count = INT_MAX;
            
        for (int i = 0; i < candidate_count; i++) {
            if (votes_got[i] < 0)
                continue;

            if (votes_got[i] > max_votes_count) {
                max_votes_count = votes_got[i];
                max_votes_candidates = vector<int>(1, i);
            } else if (votes_got[i] == max_votes_count) {
                max_votes_candidates.emplace_back(i);
            }

            if (votes_got[i] < min_votes_count) {
                min_votes_count = votes_got[i];
                min_votes_candidates = vector<int>(1, i);
            } else if (votes_got[i] == min_votes_count) {
                min_votes_candidates.emplace_back(i);
            }
        }

        if (max_votes_count * 2 > total_votes_count)
            return max_votes_candidates;
        if (max_votes_count == min_votes_count)
            return max_votes_candidates;
        for (auto i : min_votes_candidates)
            votes_got[i] = -1;
        for (auto &q : votes)
            if (!q.empty() && votes_got[q.front()] < 0)
                while(!q.empty()) {
                    q.pop();
                    if (!q.empty() && votes_got[q.front()] >= 0) {
                        votes_got[q.front()]++;
                        break;
                    }
                }
    };
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int candidate_count;
        cin >> candidate_count;
        vector<string> candidates(candidate_count);
        cin.ignore();
        for (int i = 0; i < candidate_count; i++) {
            getline(cin, candidates[i]);
        }
        vector<queue<int>> votes;
        string line;
        while (getline(cin, line)) {
            if (line == "")
                break;
            stringstream ss(line);
            votes.emplace_back();
            int candidate;
            while (ss >> candidate)
                votes.back().emplace(candidate - 1);
        }
        for (auto &i : solve(candidate_count, votes)) {
            cout << candidates[i] << "\n";
        }
        if (t) cout << "\n";
    }

    return 0;
}
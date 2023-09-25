/**
 * reference: https://knightzone.studio/2012/03/29/1578/uva%EF%BC%9A10026%EF%BC%8Dshoemakers-problem/
*/

#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id, time, fine;

    static bool cmp(const Job &lhs, const Job &rhs);
};

vector<int> solve(vector<Job> jobs) {
    sort(jobs.begin(), jobs.end(), Job::cmp);
    vector<int> result;
    for (auto &job : jobs)
        result.emplace_back(job.id);
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Job> jobs(n, {0, 0, 0});
        for (int i = 0; i < jobs.size(); i++) {
            cin >> jobs[i].time >> jobs[i].fine;
            jobs[i].id = i + 1;
        }
        auto order = solve(jobs);
        for (int i = 0; i < order.size(); i++)
            cout << order[i] << (i == order.size() - 1 ? "\n" : " ");
        if (t) cout << "\n";
    }
    
    return 0;
}

bool Job::cmp(const Job &lhs, const Job &rhs) {
    double lhs_ratio = double(lhs.time) / lhs.fine;
    double rhs_ratio = double(rhs.time) / rhs.fine;
    if (lhs_ratio < rhs_ratio)
        return true;
    if (lhs_ratio == rhs_ratio)
        return lhs.id < rhs.id;
    return false;
}
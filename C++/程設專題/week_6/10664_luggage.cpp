#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &luggages) {
    int sum = 0;
    for (auto weight : luggages) sum += weight;
    if (sum % 2) return false;

    vector<bool> available(sum + 1);
    available[0] = true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> luggages;
        int weight;
        while (ss >> weight) luggages.emplace_back(weight);
        cout << (solve(luggages) ? "YES" : "NO") << "\n";
    }
    return 0;
}


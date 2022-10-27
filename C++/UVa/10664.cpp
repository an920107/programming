#include <bits/stdc++.h>
using namespace std;

#define MAX_WEIGH 200
#define MAX_COUNT 20

void solve(vector<int> &luggages) {
    vector<int> prefixWeigh;
    prefixWeigh.emplace_back(0);
    luggages.insert(luggages.begin(), 0);
    for (auto &weigh : luggages)
        prefixWeigh.emplace_back(prefixWeigh.back() + weigh);
    if (prefixWeigh.back() % 2) {
        cout << "NO\n";
        return;
    }
    int totalWeigh = prefixWeigh.back() / 2;

    bool available[MAX_COUNT + 1][MAX_WEIGH + 1]{false};
    available[0][0] = true;
    for (int i = 0; i < luggages.size() - 1; i ++) {
        for (int weigh = 0; weigh <= totalWeigh; weigh ++) {
            if (available[i][weigh]) {
                if (luggages[i + 1] + weigh <= totalWeigh) {
                    available[i + 1][luggages[i + 1] + weigh] = true;
                }
                if (luggages[i + 1] + prefixWeigh[i + 1] - weigh <= totalWeigh) {
                    available[i + 1][weigh] = true;
                }
            }
        }
    }
    if (available[luggages.size() - 1][totalWeigh])
        cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    string line;
    vector<int> vec;
    cin >> t;
    cin.ignore();
    while (t --) {
        getline(cin, line);
        vec.clear();
        vec.emplace_back(0);
        for (auto &ch : line) {
            if (ch == ' ')
                vec.emplace_back(0);
            else if (ch != '\n')
                vec.back() = vec.back() * 10 + (ch - '0');
        }
        solve(vec);
    }
    return 0;
}
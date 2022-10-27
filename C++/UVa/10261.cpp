#include <bits/stdc++.h>
using namespace std;

void solve(int &ferryLength, vector<int> &cars) {
    vector<int> sumLength;
    sumLength.emplace_back(0);
    for (auto &len : cars)
        sumLength.emplace_back(sumLength.back() + len);

    // 記錄左側的情況
    bool **available = (bool**)malloc((cars.size() + 1) * sizeof(bool*));
    int **status = (int**)malloc((cars.size() + 1) * sizeof(int*));
    for (int i = 0; i <= cars.size(); i ++) {
        available[i] = (bool*)malloc((ferryLength + 1) * sizeof(bool));
        status[i] = (int*)malloc((ferryLength + 1) * sizeof(int));
        memset(available[i], false, (ferryLength + 1) * sizeof(bool));
        memset(status[i], -1, (ferryLength + 1) * sizeof(int));
    }
    available[0][0] = true;

    pair<int, int> longest(0, 0);
    for (int i = 0; i < cars.size() - 1; i ++)
        for (int len = 0; len <= ferryLength; len ++)
            if (available[i][len]) {
                // 放左側
                if (cars[i + 1] + len <= ferryLength) {
                    available[i + 1][cars[i + 1] + len] = true;
                    status[i + 1][cars[i + 1] + len] = 1;
                    longest = make_pair(i + 1, cars[i + 1] + len);
                }
                // 放右側
                if (cars[i + 1] + sumLength[i + 1] - len <= ferryLength) {
                    available[i + 1][len] = true;
                    status[i + 1][len] = 0;
                    longest = make_pair(i + 1, len);
                }
            }
    
    cout << longest.first << '\n';
    string result;
    for (int i = longest.first, len = longest.second; i > 0; i --) {
        if (status[i][len] == -1) continue;
        if (status[i][len] == 1) {
            result = "port\n" + result;
            len -= cars[i];
        }
        else result = "starboard\n" + result;
    }
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> vec;
    int t, ferryLength, length;
    cin >> t;
    while (t --) {
        vec.clear();
        cin >> ferryLength;
        ferryLength *= 100;
        vec.emplace_back(0);
        while (cin >> length && length)
            vec.emplace_back(length);
        solve(ferryLength, vec);
        cout << (t ? "\n" : "");
    }
    return 0;
}
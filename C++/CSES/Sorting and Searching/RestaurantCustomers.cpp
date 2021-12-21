#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, tmp, result = 0;
    map<int, int> mp;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> tmp;
        mp.insert(pair<int, int>(tmp, 1));
        cin >> tmp;
        mp.insert(pair<int, int>(tmp, -1));
    }
    tmp = 0;
    for (auto iter = mp.begin(); iter != mp.end(); iter ++) {
        tmp += iter->second;
        result = max(result, tmp);
    }
    cout << result << "\n";
    return 0;
}

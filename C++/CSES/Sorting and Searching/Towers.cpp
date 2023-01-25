#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &cubes) {
    map<int, int> topCube;
    for (int i = 0; i < cubes.size(); i ++) {
        auto iter = topCube.lower_bound(cubes[i] + 1);
        if (iter != topCube.end() && (-- iter->second) == 0)
            topCube.erase(iter);
        topCube[cubes[i]] ++;
    }

    int result = 0;
    for (auto &[cubeSize, count] : topCube)
        result += count;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> cubes(n);
    for (int i = 0; i < n; i ++)
        cin >> cubes[i];
    cout << solve(cubes) << '\n';
    return 0;
}
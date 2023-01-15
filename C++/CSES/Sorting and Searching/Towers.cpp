#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &cubes) {
    map<int, int> topCube;
    for (int i = 0; i < cubes.size(); i ++) {
        for (auto &p : topCube) {
            if (p.second > 0 && cubes[i] < p.first) {
                p.second --;
                break;
            }
        }
        try {
            topCube[cubes[i]] ++;
        } catch (const exception &e) {
            topCube[cubes[i]] = 0;
        }
    }

    int result = 0;
    for (auto &p : topCube)
        result += p.second;
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
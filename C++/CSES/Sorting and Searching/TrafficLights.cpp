#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

class Solve {
private:

    int length;
    vector<int> positions;
    set<int> lights;

public:

    Solve(int _length, const vector<int> &_positions) :
        length(_length), positions(_positions) {}

    void run() {
        lights.insert(0);
        lights.insert(length);

        multiset<int> lengths;
        lengths.insert(length);

        for (auto &pos : positions) {
            // 區間的右邊
            auto rightIter = lights.upper_bound(pos);
            auto leftIter = rightIter;
            leftIter --;

            lengths.erase(lengths.find(*rightIter - *leftIter));
            lengths.insert(pos - *leftIter);
            lengths.insert(*rightIter - pos);
            lights.insert(pos);

            cout << *lengths.rbegin() << ' ';
        }
        cout << '\n';
    }
};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int length, n;
    cin >> length >> n;
    vector<int> positions(n);
    for (int i = 0; i < n; i ++)
        cin >> positions[i];
    Solve sol(length, positions);
    sol.run();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &vec) {
    int result = 1;
    for (int start = 0; start < vec.size(); start ++) {
        int index = start, current = 1;
        bool state = true;
        for (; index < vec.size() - 1; (++ index)) {
            if (vec[index] > vec[index + 1] == state) {
                result = max(result, (++ current));
                state = !state;
            }
            else {
                start = index;
                break;
            }
        }
    }
    return result;
}

int main() {

    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i ++)
        cin >> vec[i];

    cout << solve(vec) << '\n';

    return 0;
}

// + - + - + + + - + - +
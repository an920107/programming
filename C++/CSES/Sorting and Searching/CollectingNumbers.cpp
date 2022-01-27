#include <bits/stdc++.h>
using namespace std;

stack<int> stk;

int main() {
    int n, res = 0, tmp;
    cin >> n >> tmp;
    stk.push(tmp);
    for (int i = 1; i < n; i ++) {
        cin >> tmp;
        if (tmp < stk.top()) {
            res ++;
        }
        else {
            stk.pop();
            stk.push(tmp);
        }
    }
    do {
        stk.pop();
        res ++;
    } while (!stk.empty());
    cout << res << "\n";
    return 0;
}

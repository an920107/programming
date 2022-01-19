#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, tmp_in, tmp_top, count = 0, round = 0;
    stack<int> stk;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> tmp_in;
        if ((stk.empty() || stk.top() < tmp_in) && i < n - 1) {
            count ++;
        }
        else {
            tmp_top = tmp_in;
            while (stk.top() < tmp_top) {
                stk.pop();
                tmp_top = stk.top();
            }
            round ++;
            count = 1;
        }
        stk.push(tmp_in);
    }
    cout << round << "\n";
    return 0;
}

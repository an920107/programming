#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> st;
    for (int i = 0; i < 10; i ++) {
        st.insert(st.end(), 10 - i);
    }
    for (auto &x : st)
        cout << x << ' ';
    cout << '\n';

    return 0;
}
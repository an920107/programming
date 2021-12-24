#include <bits/stdc++.h>
using namespace std;

struct Check {
    set<char> st;
    void reset();
    bool check(char);
};

void Solve();

int main() {
    Solve();
    return 0;
}

void Solve() {
    char sudo[9][9];
    Check ck;
    for (int i = 0; i < 81; i ++) {
        scanf("%c ", *sudo + i);
    }
    for (int i = 0; i < 9; i ++) {
        ck.reset();
        for (int j = 0; j < 9; j ++) {
            if (!ck.check(sudo[i][j])) {
                cout << "N\n";
                return;
            }
        }
    }
    for (int j = 0; j < 9; j ++) {
        ck.reset();
        for (int i = 0; i < 9; i ++) {
            if (!ck.check(sudo[i][j])) {
                cout << "N\n";
                return;
            }
        }
    }
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            ck.reset();
            for (int s_i = 0; s_i < 3; s_i ++) {
                for (int s_j = 0; s_j < 3; s_j ++) {
                    if (!ck.check(sudo[i + s_i][j + s_j])) {
                        cout << "N\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "Y\n";
}

void Check::reset() {
    st.clear();
    for (char i = '1'; i <= '9'; i ++)
        st.insert(i);
}

bool Check::check(char ch) {
    if (st.count(ch)){
        st.erase(ch);
        return true;
    }
    return false;
}
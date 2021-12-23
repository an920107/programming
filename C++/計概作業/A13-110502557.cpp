/**
 *  Assignment 13
 *  Name: 游宗穎
 *  Student Number: 110502557
 *  Course: 2021-CE1003-B
*/

#include <bits/stdc++.h>
using namespace std;

struct Check {
    set<char> st;
    void reset();
    bool check(char);
};

void Solve(string);

int main() {
    for (int i = 1; i <= 3; i ++) {
        Solve("sudo" + to_string(i));
    }
    return 0;
}

void Solve(string filename) {
    FILE *file = fopen((filename + ".txt").c_str(), "r");
    char sudo[9][9];
    Check ck;
    cout << filename << ":";
    for (int i = 0; i < 81; i ++) {
        fscanf(file, "%c ", *sudo + i);
    }
    for (int i = 0; i < 9; i ++) {
        ck.reset();
        for (int j = 0; j < 9; j ++) {
            if (!ck.check(sudo[i][j])) {
                cout << "N\n";
                fclose(file);
                return;
            }
        }
    }
    for (int j = 0; j < 9; j ++) {
        ck.reset();
        for (int i = 0; i < 9; i ++) {
            if (!ck.check(sudo[i][j])) {
                cout << "N\n";
                fclose(file);
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
                        fclose(file);
                        return;
                    }
                }
            }
        }
    }
    cout << "Y\n";
    fclose(file);
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
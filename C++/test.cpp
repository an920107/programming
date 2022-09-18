#include <bits/stdc++.h>
using namespace std;

#define RANGE_MAX 20
#define TERM_MIN 6
#define TERM_MAX 10

#define NEGTIVE_P 20 //(%)
#define BRACKET_P 30 //(%)
#define ABS_P 25 //(%)

void solve() {

    int tmp, bracket;
    vector<int> terms, opts, brackets_l, abs_l;

    int term = rand() % (TERM_MAX - TERM_MIN) + TERM_MIN;
    for (int i = 0; i < term; i ++) {
        tmp = rand() % 100;
        terms.emplace_back(rand() % RANGE_MAX * (tmp < NEGTIVE_P ? -1 : 1));
    }
    for (int i = 1; i < term; i ++) {
        opts.emplace_back(rand() % 4);
    }

    tmp = rand() % 100;
    if (tmp < BRACKET_P * BRACKET_P)
        bracket = 2;
    else if (tmp < BRACKET_P)
        bracket = 1;
    else bracket = 0;
    for (int i = 0; i < bracket; i ++)
        brackets_l.emplace_back(rand() % (term - 4));
    for (int i = 0; i < bracket; i ++)
        brackets_l.emplace_back(-(rand() % (term - 4) + 4));
    for (int i = 0; i < bracket * 2 - 1; i ++) {
        if (brackets_l[i] == brackets_l[i + 1]) {
            if (brackets_l[i] >= 0)
                brackets_l[i + 1] ++;
            else brackets_l[i + 1] --;
        }
    }
    // if (bracket > 1) {
    //     sort(brackets_l.begin(), brackets_l.begin() + bracket / 2 + 1);
    //     sort(brackets_l.begin() + bracket / 2 + 1, brackets_l.end());
    //     reverse(brackets_l.begin() + bracket / 2 + 1, brackets_l.end());
    // }
    // for (int i = bracket / 2 - 1; i >= 0; i --) {
    //     tmp = rand() % 100;
    //     if (tmp < ABS_P)
    //     abs_l.emplace_back(i);
    //     abs_l.emplace_back(bracket - i - 1);
    // }
    // for (auto &loc : abs_l)
    //     for (auto iter = brackets_l.begin(); iter != brackets_l.end(); iter ++)
    //         if (*iter == loc)
    //             brackets_l.erase(iter);

    for (auto &loc : brackets_l)
        if (loc == 0) cout << '(';
    cout << terms[0];
    for (int i = 1; i < term; i ++) {
        cout << ' ';
        switch (opts[i - 1]) {
            case 0: cout << "+ "; break;
            case 1: cout << "- "; break;
            case 2: cout << "× "; break;
            case 3: cout << "÷ "; break;
            default: break;
        }
        for (auto &loc : brackets_l)
            if (loc == i) cout << '(';
        // for (auto &loc : abs_l)
        //     if (loc == i) cout << '|';
        if (terms[i] < 0)
            cout << "(" << terms[i] << ")";
        else cout << terms[i];
        for (auto &loc : brackets_l) 
            if (-loc == i) cout << ')';
        // for (auto &loc : abs_l)
        //     if (-loc == i) cout << '|';
    }
    cout << '\n';
}

int main() {

    srand(time(NULL));
    freopen("output.txt", "w", stdout);

    int t = 1000;
    while (t --) {
        solve();
    }

    return 0;
}
/**
 *  Practice 1
 *  Name: 游宗穎
 *  Student Number: 110502557
 *  Course: 2021-CE1003-B
*/

#include <bits/stdc++.h>
using namespace std;

class CharSet: public set<char> {
public:
    int SetFind(char ch) {
        int i = 0;
        for (iterator it = begin(); it != end(); it ++, i ++) {
            if (*it == ch) return i;
        }
        return -1;
    }
    string SetList() {
        string str = "";
        for (iterator it = begin(); it != end(); it ++) {
            str += *it;
            str += " ";
        }
        str.pop_back();
        return str;
    }
};

int main() {
    int n;
    char ch;
    CharSet st;
    while (cin >> n) {
        if (n == -1) break;
        for (int i = 0; i < n; i ++) {
            cin >> ch;
            st.insert(ch);
        }
        cout << st.SetList() << "\n";
        cin >> ch;
        cout << st.SetFind(ch) << "\n\n";
        st.clear();
    }
    return 0;
}

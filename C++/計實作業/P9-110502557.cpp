/**
 * Practice 09
 * Name: 游宗穎
 * Student Number: 110502557
 * Course: 2021-CE1003-B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, count;
    string str;
    cin >> n;
    getline(cin, str);
    for ( ; n > 0; n --) {
        count = 1;
        getline(cin, str);
        if (str.length() == 0) {
            cout << '\n';
            continue;
        }
        for (int i = 1; i < str.length(); i ++) {
            if (str[i] != str[i - 1]) {
                cout << str[i - 1] << count;
                count = 1;
            }
            else count ++;
        }
        cout << str[str.length() - 1] << count << '\n';
    }
    return 0;
}

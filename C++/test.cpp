#include <bits/stdc++.h>
using namespace std;

void reader(const string str, set<string> &se) {
    freopen(str.c_str(), "r", stdin);
    string s;
    while (cin >> s) {
        cerr << s << '\n';
        se.insert(s);
    }
    cin.clear();
    fclose(stdin);
}

int main() {
    // FILE* file_all = fopen("url_list.txt", "r");
    // FILE* file_new = fopen("url_list_new.txt", "r");
    string line;
    set<string> st;
    reader("url_list.txt", st);
    reader("url_list_new.txt", st);
    freopen("url_list.txt", "w", stdout);
    for (string str : st) {
        cout << str << '\n';
        cerr << str << '\n';
    }
}

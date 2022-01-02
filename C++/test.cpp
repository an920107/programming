#include <bits/stdc++.h>
using namespace std;

string decTo26(int n) {
    stack<int> stk;
    string str = "";
    while (n > 0) {
        stk.push(n % 27);
        n /= 27;
    }
    while (!stk.empty()) {
        str += stk.top() + 'a' - 1;
        stk.pop();
    }
    return str;
}

bool check(string &str) {
    for (int i = str.length() - 1; i > 0; i --) {
        if (str[i] <= str[i - 1]) return false;
    }
    return true;
}

int main() {
    string tmp;
    FILE *file = fopen("test_.txt", "w");
    int t = 1;
    for (int i = 1; i < 100000000; i ++) {
        tmp = decTo26(i);
        if (check(tmp)) {
            fprintf(file, "%5d: %5s\n", t ++, tmp.c_str());
        }
    }
    return 0;
}
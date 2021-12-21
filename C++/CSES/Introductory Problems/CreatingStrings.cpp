#include <bits/stdc++.h>
using namespace std;

string CreatString(string);

int main() {
    string str, rvs, result = "";
    int n = 1;
    cin >> str;
    sort(str.begin(), str.end());
    rvs = str;
    reverse(rvs.begin(), rvs.end());
    result += str + "\n";
    while (str != rvs) {
        str = CreatString(str);
        result += str + "\n";
        n ++;
    }
    cout << n << "\n" << result;
    return 0;
}

string CreatString(string str) {
    char tmp;
    int begin, end;
    for (int loc = str.length() - 1; loc > 0; loc --) {
        if (str[loc] > str[loc - 1]) {
            loc --;
            for (int i = str.length() - 1; i > loc; i --) {
                if (str[i] > str[loc]) {
                    tmp = str[i];
                    str[i] = str[loc];
                    str[loc] = tmp;
                    sort(str.begin() + loc + 1, str.end());
                    return str;
                }
            }
        }
    }
    return str;
}

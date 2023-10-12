// reference: https://www.youtube.com/watch?v=af1oqpnH1vA

#include <bits/stdc++.h>
using namespace std;

bool solve(const string& str, const string& to_find) {
    vector<int> next_array(to_find.length());
    int prefix_len = 0;
    for (int i = 1; i < to_find.length();) {
        if (to_find[i] == to_find[prefix_len]) {
            prefix_len++;
            next_array[i++] = prefix_len;
        } else {
            if (prefix_len == 0)
                next_array[i++] = 0;
            else
                prefix_len = next_array[prefix_len - 1];
        }
    }

    for (int main_i = 0, sub_i = 0; main_i < to_find.length();) {
        if (str[main_i] == to_find[sub_i]) {
            main_i++;
            sub_i++;
        } else if (sub_i > 0) {
            sub_i = next_array[sub_i - 1];
        } else {
            main_i++;
        }

        if (sub_i == to_find.length()) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int n;
        cin >> n;
        while (n--) {
            string to_find;
            cin >> to_find;
            cout << (solve(str, to_find) ? "y" : "n") << "\n";
        }
    }

    return 0;
}
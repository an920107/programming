#include <bits/stdc++.h>
using namespace std;

int main () {
    string result = "";
    bool odd = false;
    char chr;
    int letter[26] = {0}, odd_i;
    while (cin >> chr) {
        letter[int(chr) - 65] ++;
    }
    for (int i = 0; i < 26; i ++) {
        if (letter[i] % 2 == 1) {
            if (odd) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            odd = true;
            odd_i = i;
            letter[i] --;
        }
        letter[i] /= 2;
        for (int j = 0; j < letter[i]; j ++)
            result += char(i + 65);
    }
    cout << result;
    if (odd) cout << char(odd_i + 65);
    for (int i = 25; i >= 0; i --)
        for (int j = 0; j < letter[i]; j ++)
            cout << char(i + 65);
    cout << '\n';
    return 0;
}

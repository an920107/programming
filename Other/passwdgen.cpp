#include <bits/stdc++.h>

using namespace std;

int main() {
    int length, str_len;
    string str;
    srand(time(NULL));

    while (length >= 0) {
        str = "";
        for (int i = 48; i <= 57; i ++)
            str += char(i);
        for (int i = 65; i <= 90; i ++)
            str += char(i);
        for (int i = 97; i <= 122; i ++)
            str += char(i);
        str_len = str.length();

        cout << "Length of the password: ";
        for (cin >> length; length >= 1; length --)
            cout << str[float(rand()) / RAND_MAX * (str_len - 0)];
        cout << '\n';
    }
    return 0;
}
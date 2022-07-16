#include <bits/stdc++.h>
using namespace std;

int main() {

    srand(time(NULL));

    string str = "";
    for (char c = '0'; c <= '9'; c ++)
        str += c;
    for (char c = 'a'; c <= 'z'; c ++)
        str += c;
    for (char c = 'A'; c <= 'Z'; c ++)
        str += c;
    str += "!@#$%^&*/()-_=+";

    for (int i = 0; i < 16; i ++)
        cout << str[rand() % str.length()];
    cout << endl;

    return 0;
}
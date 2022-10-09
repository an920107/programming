#include <bits/stdc++.h>
using namespace std;

#define int128 __int128_t

int128 readInt128() {
    int128 num = 0;
    char ch;
    while (ch = getchar()) {
        if (ch == ' ' || ch == '\n')
            break;
        num = num * 10 + ch - '0';
    }
    return num;
}

void printInt128(const int128 &num) {
    if (num >= 10)
        printInt128(num / 10);
    putchar(num % 10 + '0');
}

string intToStrAndReverse(int128 num) {
    string str = "";
    while (num) {
        str += (char)(num % 10 + '0');
        num /= 10;
    }
    return str;
}

int main() {
    int128 n = readInt128();
    cout << intToStrAndReverse(n) << endl;
    return 0;
}
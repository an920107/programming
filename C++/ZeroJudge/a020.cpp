#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int sum = 0, cod;
    cin >> str;
    switch (str[0]) {
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
        cod = int(str[0] - 55);
        break;
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
        cod = int(str[0] - 56);
        break;
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
        cod = int(str[0] - 57);
        break;
    case 'I':
        cod = 34;
        break;
    case 'O':
        cod = 35;
        break;
    case 'W':
        cod = 32;
        break;
    case 'X':
        cod = 30;
        break;
    case 'Y':
        cod = 31;
        break;
    case 'Z':
        cod = 33;
        break;
    }
    sum += cod / 10 + cod % 10 * 9;
    for (int i = 1; i < 9; i++) {
        sum += (int(str[i]) - 48) * (9 - i);
    }
    sum += int(str[9]) - 48;
    if (sum % 10 == 0) cout << "real\n";
    else cout << "fake\n";
    return 0;
}

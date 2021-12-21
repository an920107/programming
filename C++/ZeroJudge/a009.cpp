#include <iostream>
#include <string>

#define MOVE 7

using namespace std;

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        str[i] -= MOVE;
    }
    cout << str << '\n';
    return 0;
}

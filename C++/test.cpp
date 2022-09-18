#include <bits/stdc++.h>
using namespace std;

int main() {

    stringstream ss;
    ss << "1+25";
    char ch;
    int i;
    cout << ss.rdbuf()->in_avail() << '\n';
    ss >> i;
    cout << ss.rdbuf()->in_avail() << '\n';
    ss >> ch;
    cout << ss.rdbuf()->in_avail() << '\n';
    ss >> i;
    cout << ss.rdbuf()->in_avail() << '\n';
    cout << i << ch;

    return 0;
}
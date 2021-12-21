/**
 *  Practice 10
 *  Name: 游宗穎
 *  Student Number: 110502557
 *  Course: 2021-CE1003-B
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str, rvs;
    while (cin >> str) {
        if (str == "-1") break;
        rvs = str;
        reverse(rvs.begin(), rvs.end());
        printf(str == rvs ? "Palindrome!\n" : "Not Palindrome!\n");
    }
    return 0;
}

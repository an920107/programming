/**
 *  Assignment 14
 *  Name: 游宗穎
 *  Student Number: 110502557
 *  Course: 2021-CE1003-B
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void solve(string &str) {
    int n, max = 1, len = str.length();
    long long num_dec, mul;
    vector<int> vec;
    for (auto &ch : str) {
        if (ch <= 57) vec.push_back(ch - 48);
        else if (ch <= 90) vec.push_back(ch - 55);
        else vec.push_back(ch - 61);
    }
    for (auto &num : vec)
        if (num > max) max = num;
    for (n = max + 1; n <= 62; n ++) {
        mul = 1; num_dec = 0;
        for (int i = len - 1; i >= 0; i --) {
            num_dec += vec[i] * mul;
            mul *= n;
        }
        if (num_dec % (n - 1) == 0) {
            cout << n << "\n";
            return;
        }
    }
    cout << "such number is impossible!\n";
}

int main() {
    string str;
    while (cin >> str) {
        if (str == "-1") break;
        solve(str);
    }
    return 0;
}

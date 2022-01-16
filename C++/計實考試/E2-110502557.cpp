/**
 * Exam 2
 * Name: 游宗穎
 * Student Number: 110502557
 * Course: 2021-CE1001B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    FILE *file_r = fopen("input.txt", "r");
    FILE *file_w = fopen("output.txt", "w");
    stack<bool> stk, bit8;
    string res = "";
    char tmp;
    int count = 0, equ = 0;
    while (fscanf(file_r, "%c", &tmp) != EOF) {
        for (int i = 0; i < 8; i ++) {
            bit8.push(tmp % 2);
            tmp /= 2;
        }
        for (int i = 0; i < 8; i ++) {
            stk.push(bit8.top());
            bit8.pop();
        }
        count ++;
    }
    equ = count * 6 % 4 / 2;
    for (int i = 0; i < equ; i ++) {
        res += '=';
        stk.push(0);
        stk.push(0);
    }
    while (!stk.empty()) {
        tmp = 0;
        for (int i = 0; i < 6; i ++) {
            tmp += stk.top() << i;
            stk.pop();
        }
        if (tmp <= 25) tmp += 'A';
        else if (tmp <= 51) tmp += 'a' - 26;
        else if (tmp <= 61) tmp += '0' - 52;
        else if (tmp == 62) tmp = '+';
        else tmp = '-';
        res = tmp + res;
    }
    fprintf(file_w, "%s", res.c_str());
    return 0;
}
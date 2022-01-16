/**
 * Exam 1
 * Name: 游宗穎
 * Student Number: 110502557
 * Course: 2021-CE1001B
 */

#include <bits/stdc++.h>
using namespace std;

FILE *file_r;
FILE *file_w;

void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        fprintf(file_w, "%c%c\n", A, C);
    }
    else {
        hanoi(n - 1, A, C, B);
        hanoi(1, A, B, C);
        hanoi(n - 1, B, A, C);
    }
}

int main() {
    file_r = fopen("N.txt", "r");
    file_w = fopen("110502557.txt", "w");
    string res = "";
    int n;
    fscanf(file_r, "%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
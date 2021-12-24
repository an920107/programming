/**
 *  Practice 13
 *  Name: 游宗穎
 *  Student Number: 110502557
 *  Course: 2021-CE1003-B
*/

#include <bits/stdc++.h>
using namespace std;

void Solve(string);
bool Result(int); 

int main() {
    for (int i = 1; i <= 3; i ++) {
        Solve("ox" + to_string(i));
    }
    return 0;
}

void Solve(string filename) {
    FILE *file = fopen((filename + ".txt").c_str(), "r");
    int o_c = 0;
    char ox[3][3];
    printf("%s: ", filename.c_str());
    for (int i = 0; i < 9; i ++) {
        fscanf(file, "%c\n", *ox + i);
    }
    for (int i = 0; i < 3; i ++) {
        o_c = 0;
        for (int j = 0; j < 3; j ++) {
            o_c += ox[i][j] == 'o';
        }
        if (Result(o_c)) {fclose(file); return;}
    }
    for (int j = 0; j < 3; j ++) {
        o_c = 0;
        for (int i = 0; i < 3; i ++) {
            o_c += ox[i][j] == 'o';
        }
        if (Result(o_c)) {fclose(file); return;}
    }
    o_c = 0;
    for (int i = 0; i < 3; i ++) {
        o_c += ox[i][i] == 'o';
    }
    if (Result(o_c)) {fclose(file); return;}
    o_c = 0;
    for (int i = 0; i < 3; i ++) {
        o_c += ox[i][2 - i] == 'o';
    }
    if (Result(o_c)) {fclose(file); return;}
    printf("tie\n");
    fclose(file);
}

bool Result(int o_c) {
    if (o_c == 3) {
        printf("Owin\n");
        return true;
    }
    else if (o_c == 0) {
        printf("Xwin\n");
        return true;
    }
    return false;
}
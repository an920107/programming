/**
 * Exam 3
 * Name: 游宗穎
 * Student Number: 110502557
 * Course: 2021-CE1001B
 */

#include <bits/stdc++.h>
using namespace std;

int solve(string filename) {
    FILE *file = fopen(filename.c_str(), "r");
    multimap<int, char> mp; mp.clear();
    vector<pair<int, char>> vec; vec.clear();
    int tmp_i;
    char tmp_c, tmp_str[10];
    bool flag;
    for (int i = 0; i < 5; i ++) {
        fscanf(file, "%s %c", tmp_str, &tmp_c);
        if (tmp_str[0] == 'A') tmp_i = 1;
        else if (tmp_str[0] == 'J') tmp_i = 11;
        else if (tmp_str[0] == 'Q') tmp_i = 12;
        else if (tmp_str[0] == 'K') tmp_i = 13;
        else if (tmp_str[1] == '0') tmp_i = 10;
        else tmp_i = tmp_str[0] - '0';
        mp.insert(pair<int, char>(tmp_i, tmp_c));
    }
    for (auto p : mp) {
        vec.push_back(p);
        cout << p.first << p.second << "\n";
    }
    // 1
    flag = true;
    for (int i = 1; i < 5; i ++) {
        if (vec[i].first - vec[i - 1].first != 1) flag = false;
        if (vec[i].second != vec[i - 1].second) flag = false;
    }
    if (flag) {
        fclose(file);
        return 1;
    }
    // 2
    if (mp.count(vec[0].first) == 4 || mp.count(vec[1].first) == 4) {
        fclose(file);
        return 2;
    }
    // 3
    if ((mp.count(vec[0].first) == 2 && mp.count(vec[2].first) == 3) ||
        (mp.count(vec[0].first) == 3 && mp.count(vec[3].first) == 2)) {
        fclose(file);
        return 3;
    }
    // 4
    flag = true;
    for (int i = 1; i < 5; i ++) {
        if (vec[i].second != vec[i - 1].second) flag = false;
    }
    if (flag) {
        fclose(file);
        return 4;
    }
    // 5
    flag = true;
    for (int i = 1; i < 5; i ++) {
        if (vec[i].first - vec[i - 1].first != 1) flag = false;
    }
    if (flag) {
        fclose(file);
        return 5;
    }
    // 6
    if (mp.count(vec[0].first) == 3 || mp.count(vec[1].first) == 3 || mp.count(vec[2].first) == 3) {
        fclose(file);
        return 6;
    }
    // 7
    if ((mp.count(vec[0].first) == 2 && mp.count(vec[2].first) == 2) ||
        (mp.count(vec[0].first) == 2 && mp.count(vec[3].first) == 2) ||
        (mp.count(vec[1].first) == 2 && mp.count(vec[3].first) == 2)) {
        fclose(file);
        return 7;
    }
    // 8
    if (mp.count(vec[0].first) == 2 || mp.count(vec[1].first) == 2 || mp.count(vec[2].first) == 2 || mp.count(vec[3].first)) {
        fclose(file);
        return 8;
    }
    // 9
    fclose(file);
    return 9;
}

int main() {
    string filename;
    while (cin >> filename) {
        if (filename == "-1") break;
        cout << solve(filename) << "\n";
    }
    return 0;
}
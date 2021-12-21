/**
 *  Assignment 09
 *  Name: 游宗穎
 *  Student Number: 110502557
 *  Course: 2021-CE1003-B
*/

#include <bits/stdc++.h>
using namespace std;

int TriangleType(int*);

int main() {
    int len[3];
    cout << "Length of the first side: "; cin >> len[0];
    cout << "Length of the second side: "; cin >> len[1];
    cout << "Length of the third side: "; cin >> len[2];

    sort(len, len + 3);
    switch(TriangleType(len)) {
        case 0: cout << "Not triangle\n"; break;
        case 1: cout << "Regular triangle\n"; break;
        case 2: cout << "Isosceles triangle\n"; break;
        case 3: cout << "Right triangle\n"; break;
        default: cout << "Triangle\n"; break;
    }
    return 0;
}

int TriangleType(int* len) {
    if (*(len) + *(len + 1) <= *(len + 2)) return 0;
    if (*(len) == *(len + 1) && *(len + 1) == *(len + 2)) return 1;
    if (*(len) == *(len + 1) || *(len + 1) == *(len + 2)) return 2;
    if (*(len) * *(len) + *(len + 1) * *(len + 1) == *(len + 2) * *(len + 2)) return 3;
    return 4;
}

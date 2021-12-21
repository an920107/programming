/*
*   Practice 08
*   Name: 游宗穎
*   Student Number: 110502557
*   Course: 2021-CE1003-B
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    string name, st_id;
    float eng, mth, chi;
    int eng_w, mth_w, chi_w;

    cout << "Please input your name : "; cin >> name;
    cout << "Please input your student ID : "; cin >> st_id;
    cout << "English score : "; cin >> eng;
    cout << "Math score : "; cin >> mth;
    cout << "Chinese score : "; cin >> chi;
    cout << "English weight : "; cin >> eng_w;
    cout << "Math weight : "; cin >> mth_w;
    cout << "Chinese weight : "; cin >> chi_w;

    cout << "\nStudent name : " << name;
    cout << "\nStudent ID : " << st_id;
    cout << "\nArithmetic average : " << int((eng + mth + chi) / 3);
    cout << "\nWeightd average : " << int((eng * eng_w + mth * mth_w + chi * chi_w) / (eng_w + mth_w + chi_w));
    cout << '\n';
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Date {
    int year;
    int month;
    int day;

    Date() {}
    explicit Date(int _year, int _month, int _day):
        year(_year), month(_month), day(_day) {}
};

int main() {
    int y, m, d;

    Date holiday{2004, 4, 26};

    cout << "Input the festival's y m d: ";
    cin >> y >> m >> d;
    Date festival{y, m, d};

    printf("Holiday: %d/%d/%d\n", holiday.year, holiday.month, holiday.day);
    printf("Festival: %d/%d/%d\n", festival.year, festival.month, festival.day);

    return 0;
}
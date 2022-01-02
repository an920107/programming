#include <iostream>

using namespace std;

bool leap_or_not(int);

int main() {
    const int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int y[2], m[2], d[2], day_count[2];
    while (cin >> y[0] >> m[0] >> d[0] >> y[1] >> m[1] >> d[1]) {
        for (int i = 0; i < 2; i++) {
            day_count[i] = 0;
            for (int y_acc = 1; y_acc < y[i]; y_acc++) {
                day_count[i] += 365;
                if (leap_or_not(y_acc)) day_count[i]++;
            }
            for (int m_acc = 1; m_acc < m[i]; m_acc++) {
                day_count[i] += month_days[m_acc - 1];
                if (m_acc == 2 && leap_or_not(y[i])) day_count[i]++;
            }
            day_count[i] += d[i];
        }
        if (day_count[0] > day_count[1]) cout << day_count[0] - day_count [1] << '\n';
        else cout << day_count[1] - day_count [0] << '\n';
    }
    return 0;
}

bool leap_or_not(int y) {
    return((((y) % 4) == 0 && ((y) % 100) != 0) || ((y) % 400) == 0);
}
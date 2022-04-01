#include <bits/stdc++.h>
using namespace std;

class Time {
private:
    int date_m, date_d;
    int begin_h, begin_m;
    int end_h, end_m;

    bool date_set, begin_set, end_set;

public:
    Time() {}
    ~Time() {}

    void setDate(int, int);
    void setBeginTime(int, int);
    void setEndTime(int, int);
    double getPeriod();
    double writeTextLine(FILE*);
};

int main() {
    vector<Time> working;
    string name, line, context;
    char tmp[500];
    double total = 0;
    int x, y;

    cout << "Input file name: ";
    cin >> name;
    FILE *file = fopen((name + ".txt").c_str(), "w");
    fprintf(file, "");
    file = fopen((name + ".txt").c_str(), "a");

    while (true) {
        cout << "\n==============================\n";
        working.push_back(*new Time());

        cout << "\nFormat: month day (-1 -1 to exit)\nInput the date: ";
        cin >> x >> y;
        if (x < 0 || y < 0) break;
        working.back().setDate(x, y);

        cout << "\nFormat: hr min (-1 -1 to exit)\nInput the begin time: ";
        cin >> x >> y;
        if (x < 0 || y < 0) break;
        working.back().setBeginTime(x, y);

        cout << "\nFormat: hr min (-1 -1 to exit)\nInput the end time: ";
        cin >> x >> y;
        if (x < 0 || y < 0) break;
        working.back().setEndTime(x, y);
    }

    cout << "==============================\n";
    for(Time obj : working) {
        total += obj.writeTextLine(file);
    }
    fprintf(file, "Total_%.1lfHr\n", total);

    context = "";
    file = fopen((name + ".txt").c_str(), "r");
    while (fscanf(file, "%s\n", tmp) != EOF) {
        line = string(tmp);
        while (line.find(" ") != string::npos) {
            line = line.replace(line.find(" "), 1, "0");
        }
        context += line + "\n";
    }
    file = fopen((name + ".txt").c_str(), "w");
    fprintf(file, context.c_str());
    cout << "\nDone!\n";

    return 0;
}

double Time::getPeriod() {
    return (end_h * 60 + end_m - begin_h * 60 - begin_m) / 60.0;
}

void Time::setDate(int m, int d) {
    this->date_m = m;
    this->date_d = d;
    this->date_set = true;
}

void Time::setBeginTime(int h, int m) {
    this->begin_h = h;
    this->begin_m = m;
    this->begin_set = true;
}

void Time::setEndTime(int h, int m) {
    this->end_h = h;
    this->end_m = m;
    this->end_set = true;
}

double Time::writeTextLine(FILE *file) {
    if (!(date_set && begin_set && end_set)) return 0;
    fprintf(file, "%2d/%2d_%2d:%2d~%2d:%2d_%.1lfHr\n",
        date_m, date_d, begin_h, begin_m, end_h, end_m, getPeriod());
    return getPeriod();
}
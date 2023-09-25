#include <bits/stdc++.h>
using namespace std;

/** classes and structs declaration */

struct Time {
    int month, day, hour, minute;

    Time(const string&);
    bool operator<(const Time&) const;
};

enum Behavior { ENTER, EXIT };

struct Record {
    string name;
    Time time;
    Behavior behavior;
    int position;

    Record(const string&, const Time&, Behavior, int);
    static bool cmp(const Record&, const Record&);
};

/** core */

map<string, int> solve(const vector<int> &rate, vector<Record> &records) {
    sort(records.begin(), records.end(), Record::cmp);

    map<string, int> bills;
    map<string, const Record*> entered;

    for (auto &record : records) {
        if (record.behavior == Behavior::ENTER)
            entered[record.name] = &record;
        else {
            auto it = entered.find(record.name);
            if (it != entered.end()) {
                const int distance = abs(record.position - it->second->position);
                bills[record.name] += distance * rate[it->second->time.hour] + 100;
                entered.erase(it);
            }
        }
    }

    for (auto bill : bills)
        bills[bill.first] += 200;

    return bills;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> rate(24);
        for (int i = 0; i < rate.size(); i++)
            cin >> rate[i];
        vector<Record> records;
        string line;
        cin.ignore();
        while (getline(cin, line)) {
            if (line == "")
                break;
            stringstream ss(line);
            string token;
            vector<string> args;
            while (ss >> token)
                args.push_back(token);
            records.emplace_back(
                args[0],
                Time(args[1]),
                args[2] == "enter" ? Behavior::ENTER : Behavior::EXIT,
                stoi(args[3]));
        }
        for (auto p : solve(rate, records))
            printf("%s $%.2lf\n", p.first.c_str(), double(p.second) / 100);
        if (t)
            printf("\n");
    }

    return 0;
}

/** classes and structs definition */

Time::Time(const string &_str) :
    month(stoi(_str.substr(0, 2))),
    day(stoi(_str.substr(3, 2))),
    hour(stoi(_str.substr(6, 2))),
    minute(stoi(_str.substr(9, 2))) {}

bool Time::operator<(const Time &other) const {
    if (month < other.month) return true;
    if (month == other.month) {
        if (day < other.day) return true;
        if (day == other.day) {
            if (hour < other.hour) return true;
            if (hour == other.hour) {
                if (minute < other.minute) return true;
            }
        }
    }
    return false;
}

Record::Record(const string& _name, const Time& _time, Behavior _behavior, int _position) :
    name(_name), time(_time), behavior(_behavior), position(_position) {}

bool Record::cmp(const Record &lhs, const Record &rhs) {
    if (lhs.time < rhs.time) return true;
    return false;
}
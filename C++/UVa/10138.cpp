#include <bits/stdc++.h>
using namespace std;

int price[24];

typedef struct time {
    int month, day, hour, minute;
    time() {}
    time(string &str) {
        char tmp;
        stringstream ss;
        ss << str;
        ss >> month >> tmp >> day >> tmp >> hour >> tmp >> minute;
    }
    friend bool operator<(const time &x, const time &y) {
        if (x.month < y.month) return true;
        if (x.day < y.day) return true;
        if (x.hour < y.hour) return true;
        if (x.minute < y.minute) return true;
        return false;
    }
} Time;

typedef struct record {
    string license;
    Time time;
    bool inOut;
    int loc;
    record() {}
    record(string &line) {
        string tmp;
        stringstream ss;
        ss << line;
        ss >> license >> tmp;
        time = Time(tmp);
        ss >> tmp;
        inOut = (tmp == "exit");
        ss >> loc;
    }
} Record;

auto recordCmp = [](const Record &x, const Record &y) {
    if (x.license < y.license) return true;
    if (x.time < y.time) return true;
    return false;
};

void solve() {
    string line;
    stringstream ss;
    vector<Record> data;
    map<string, int> result;
    getline(cin, line);
    getline(cin, line);
    ss << line;
    for (int i = 0; i < 24; i ++)
        ss >> price[i];
    while (getline(cin, line)) {
        if (line == "") break;
        data.emplace_back(Record(line));
    }
    sort(data.begin(), data.end(), recordCmp);
    for (auto iter = data.begin(); iter != data.end(); ++ iter) {
        auto last = iter ++;
        if (last == data.end()) break;
        if ((*iter).license != (*last).license) {
            -- iter;
            continue;
        }
        if ((*iter).inOut == (*last).inOut)
            continue;
        auto fd = result.find((*iter).license);
        int cost = price[(*last).time.hour] * abs((*iter).loc - (*last).loc) + 100;
        if (fd == result.end())
            result.insert(make_pair((*iter).license, cost + 200));
        else (*fd).second += cost;
    }
    for (auto &p : result)
        cout << p.first << " $" << p.second / 100 << '.' << p.second % 100 << '\n';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t --)
        solve();
    return 0;
}
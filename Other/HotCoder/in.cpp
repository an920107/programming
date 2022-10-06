#include <bits/stdc++.h>
using namespace std;

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
        if (x.month != y.month) return x.month < y.month;
        if (x.day != y.day) return x.day < y.day;
        if (x.hour != y.hour) return x.hour < y.hour;
        return x.minute < y.minute;
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
    if (x.license == y.license) return x.time < y.time;
    return x.license < y.license;
};

void solve(const int &t) {
    int price[24];
    string line;
    stringstream ss;
    vector<Record> data;
    map<string, int> result;
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
        if (iter == data.end()) break;
        if ((*last).license != (*iter).license || (*last).inOut >= (*iter).inOut) {
            -- iter;
            continue;
        }
        auto fd = result.find((*iter).license);
        int cost = price[(*last).time.hour] * abs((*iter).loc - (*last).loc) + 100;
        if (fd == result.end())
            result.insert(make_pair((*iter).license, cost + 200));
        else (*fd).second += cost;
    }
    for (auto &p : result)
        cout << p.first << " $" << p.second / 100 << '.'
            << setw(2) << setfill('0') << p.second % 100 << '\n';
    if (t) cout << '\n';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    string tmp;
    cin >> t;
    getline(cin, tmp);
    getline(cin, tmp);
    while (t --)
        solve(t);
    return 0;
}
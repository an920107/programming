#include <bits/stdc++.h>
using namespace std;

typedef struct time {

    int h, m;

    time() {}
    time(const string &str) {
        stringstream ss;
        char tmp;
        ss << str;
        ss >> h >> tmp >> m;
    }

    void printString() {
        cout << h << ':' << setw(2) << setfill('0') << m;
    }

    const int operator-(const time &x) {
        return this->h * 60 + this->m - x.h * 60 - x.m;
    }
} Time;

auto timeCmp = [](const Time &x, const Time &y) {
    return x.h * 60 + x.m < y.h * 60 + y.m;
};

void solve(int &t) {

    static int day = 1;

    string line;
    multiset<Time, decltype(timeCmp)> timeSet(timeCmp);
    timeSet.insert(Time("10:00"));
    timeSet.insert(Time("18:00"));
    getline(cin, line);
    while (t --) {
        getline(cin, line);
        timeSet.insert(Time(line.substr(0, 5)));
        timeSet.insert(Time(line.substr(6, 5)));
    }
    map<int, Time> mp;
    for (auto iter = timeSet.begin(); iter != timeSet.end(); ++ iter) {
        Time before = *iter, after = *(++ iter);
        mp.insert(make_pair(after - before, before));
    }
    pair<int, Time> result = *mp.rbegin();
    cout << "Day #" << (day ++) << ": the longest nap starts at ";
    result.second.printString();
    cout << " and will last for ";
    if (result.first >= 60)
        cout << result.first / 60 << " hours and " << result.first % 60 << " minutes.\n";
    else cout << result.first << " minutes.\n";

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    while (cin >> t) {
        if (t == 0) break;
        solve(t);
    }

    return 0;
}

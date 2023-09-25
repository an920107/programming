#include <bits/stdc++.h>
using namespace std;

/** classes and structs declaration */

class Time {
private:
    int hours, minutes;

public:
    Time(int, int);
    Time(int);
    Time(string);
    string to_string() const;
    string to_detailed_string() const;
    int to_minutes() const;
};

struct Todo {
    Time start, end;
    string subject;

    Todo(const Time&, const Time&, const string&);
};

/** core */

#define MINUTES_PER_DAY 1440

string solve(vector<Todo> &todos) {
    vector<bool> available(MINUTES_PER_DAY, true);
    for (auto &todo : todos)
        for (int m = todo.start.to_minutes(); m < todo.end.to_minutes(); m++)
            available[m] = false;

    const Time fisrt(10, 0), last(18, 0);
    int current_nap_index = fisrt.to_minutes(), current_nap_length = 0;
    map<int, int> longest_nap_map;
    for (int m = fisrt.to_minutes(); m <= last.to_minutes(); m++) {
        if (available[m] && m < last.to_minutes()) {
            if (current_nap_length == 0)
                current_nap_index = m;
            current_nap_length++;
        } else if (current_nap_length > 0) {
            longest_nap_map[current_nap_index] = current_nap_length;
            current_nap_index = m;
            current_nap_length = 0;
        }
    }

    int longest_nap_index, longest_nap_length = 0;
    for (auto &p : longest_nap_map) {
        if (p.second > longest_nap_length) {
            longest_nap_index = p.first;
            longest_nap_length = p.second;
        }
    }

    return "the longest nap starts at " +
           Time(longest_nap_index).to_string() +
           " and will last for " +
           Time(longest_nap_length).to_detailed_string() +
           ".";
}

int main() {
    int case_count = 1, t;
    while (cin >> t) {
        string start, end, subject;
        vector<Todo> todos;
        while (t--) {
            cin >> start >> end;
            getline(cin, subject);
            if (subject.length() > 0)
                subject = subject.substr(1);
            todos.emplace_back(start, end, subject);
        }
        cout << "Day #" << case_count << ": " << solve(todos) << "\n";
        case_count++;
    }

    return 0;
}

/** classes and structs definition */

Time::Time(int _hours, int _minutes) :
    hours(_hours), minutes(_minutes) {}

Time::Time(int _minutes) :
    hours(_minutes / 60), minutes(_minutes % 60) {}

Time::Time(string _str) :
    hours(stoi(_str.substr(0, 2))), minutes(stoi(_str.substr(3, 2))) {}

string Time::to_string() const {
    stringstream ss;
    string hours_str, minutes_str;
    ss << right << setw(2) << setfill('0');
    ss << hours;
    ss >> hours_str;
    ss.clear();
    ss << right << setw(2) << setfill('0');
    ss << minutes;
    ss >> minutes_str;
    return hours_str + ":" + minutes_str;
}

string Time::to_detailed_string() const {
    stringstream ss;    
    string hours_str, minutes_str, result;
    if (hours > 0) {
        ss << hours;
        ss >> hours_str;
        result += hours_str + " hours and ";
        ss.clear();
    }
    ss << minutes;
    ss >> minutes_str;
    result += minutes_str + " minutes";
    return result;
}

inline int Time::to_minutes() const {
    return hours * 60 + minutes;
}

Todo::Todo(const Time &_start, const Time &_end, const string &_subject) :
    start(_start), end(_end), subject(_subject) {}
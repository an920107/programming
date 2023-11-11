#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}
};


int main() {
    map<string, int> m;
    m["a"]++;
    m["b"] = 20;
    for (auto p : m) {
        cout << p.first << " " << p.second << endl;
    }

    set<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(-1);
    for (auto p : s) {
        cout << p << endl;
    }
    if (s.find(5) != s.end()) {
        cout << "yes" << endl;
    };

    double d;

    printf("%.2lf\n", d);


    return 0;
}
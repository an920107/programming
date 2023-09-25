/**
 * reference: https://blog.csdn.net/metaphysis/article/details/6450400
*/

#include <bits/stdc++.h>
using namespace std;

struct Turtle {
    int id;
    string name;

    Turtle(int _id, string _name) :
        id(_id), name(_name) {}

    Turtle() : Turtle(0, "") {}
};

vector<Turtle> solve(vector<Turtle> &turtles) {
    vector<Turtle> result;
    for (int id = turtles.size() - 1; id > 0; id--) {
        int prev, curr;
        for (int loc = 0; loc < turtles.size(); loc++) {
            if (turtles[loc].id == id)
                curr = loc;
            else if (turtles[loc].id == id - 1)
                prev = loc;
        }
        if (prev > curr) {
            auto tmp = turtles[prev];
            result.push_back(tmp);
            turtles.erase(turtles.begin() + prev);
            turtles.insert(turtles.begin(), tmp);
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Turtle> origin(n);
        cin.ignore();
        for (int i = 0; i < n; i++)
            getline(cin, origin[i].name);
        for (int i = 0; i < n; i++) {
            string current_name;
            getline(cin, current_name);
            for (auto &turtle : origin)
                if (turtle.name == current_name)
                    turtle.id = i;
        }
        for (auto &turtle : solve(origin))
            cout << turtle.name << "\n";
        cout << "\n";
    }
    return 0;
}
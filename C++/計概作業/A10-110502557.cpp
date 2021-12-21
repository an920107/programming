/**
 *  Assignment 10
 *  Name: 游宗穎
 *  Student Number: 110502557
 *  Course: 2021-CE1003-B
*/

#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    struct Link {
        char value;
        Link *lastPtr = nullptr;
        Link *nextPtr = nullptr;
    };
    Link *lnk = new Link;
    Link *begin = lnk, *end = lnk;

public:
    void push(char ch) {
        Link *tmp = lnk;
        lnk = new Link;
        lnk->value = ch;
        lnk->lastPtr = tmp;
        tmp->nextPtr = lnk;
        end = lnk;
    }

    string pop() {
        if (begin == end) return "empty";
        string result = "";
        Link *tmp = lnk->lastPtr;
        result += lnk->value;
        delete(lnk);
        lnk = tmp;
        end = lnk;
        return result;
    }

    string list() {
        if (begin == end) return "";
        string result = "", tmp_str;
        Link *irr = begin;
        while (irr != end) {
            irr = irr->nextPtr;
            tmp_str = irr->value;
            result += tmp_str + " ";
        }
        return result;
    }
};

int main() {
    char ch;
    string str;
    Stack stk;
    while (cin >> str) {
        if (str == "push") {
            cin >> ch;
            stk.push(ch);
        }
        else if (str == "pop")
            cout << stk.pop() << '\n';
        else if (str == "list")
            cout << stk.list() << '\n';
        else break;
    }
    return 0;
}

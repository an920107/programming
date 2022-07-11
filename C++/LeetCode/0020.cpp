#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2) return false;
        stack<char> stk;
        stk.emplace('X');
        for (char& ch : s) {
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    stk.emplace(ch);
                    break;
                case ')':
                    if (stk.top() != '(') return false;
                    stk.pop();
                    break;
                case ']':
                    if (stk.top() != '[') return false;
                    stk.pop();
                    break;
                case '}':
                    if (stk.top() != '{') return false;
                    stk.pop();
                    break;
                default: break;
            }
        }
        stk.pop();
        return stk.empty();
    }
};

int main() {
    
    Solution sol;
    cout << sol.isValid("()[(()]{}") << endl;

    return 0;
}
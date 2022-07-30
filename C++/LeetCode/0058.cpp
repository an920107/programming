#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        for (int i = s.length() - 1; i >= 0; -- i) {
            if (s[i] == ' ') continue;
            for (int j = i; j >= 0; -- j) {
                if (s[j] == ' ')
                    return i - j;
            }
            return i + 1;
        }
        return s.length() + 1;
    }
};

int main() {
    
    Solution sol;
    cout << sol.lengthOfLastWord("f") << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main() {
    
    Solution sol;
    cout << sol.strStr("apple", "b") << endl;

    return 0;
}
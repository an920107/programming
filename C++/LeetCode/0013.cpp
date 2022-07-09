#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const map<string, int> mp = {
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000}
    };

public:
    int romanToInt(string s) {
        for (int i = 0; i < s.length(); i ++) {
            
        }
    }
};

int main() {
    
    Solution sol;
    cout << sol.romanToInt("I");

    return 0;
}

/**
 * I -> 1
 * V -> 5
 * X -> 10
 * L -> 50
 * C -> 100
 * D -> 500
 * M -> 1000
 */
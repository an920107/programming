#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "", compare = "";
        set<string> st;
        for (string& s : strs) {
            st.insert(s);
        }
        auto iter = st.end();
        string last = *(-- iter);
        string first = *st.begin();
        for (int size = 1; size <= first.length(); size ++) {
            compare = first.substr(0, size);
            if (last.find(compare) == 0)
                ans = compare;
            else break;
        }
        return ans;
    }
};

int main() {
    
    vector<string> strs = {"flower", "flow", "flight"}; 
    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;;

    return 0;
}
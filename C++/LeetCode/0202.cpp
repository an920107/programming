#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    set<int> st;    
public:
    bool isHappy(int n) {
        if (n == 1) {
            st.clear();
            return true;
        }
        if (st.find(n) != st.end()) {
            st.clear();
            return false;
        }
        st.insert(n);
        int x = 0, p;
        while (n > 0) {
            p = n % 10;
            x += p * p;
            n /= 10;
        }
        return isHappy(x);
    }
};

int main() {
    Solution sol;
    cout << sol.isHappy(2) << endl;
    return 0;
}
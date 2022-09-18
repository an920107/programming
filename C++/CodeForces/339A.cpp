#include <bits/stdc++.h>
using namespace std;

int main() {
    
    multiset<int> st;
    stringstream ss;
    string str;
    int num;
    char temp;
    cin >> str;
    ss << str;
    ss >> num;
    st.insert(num);
    while (ss.rdbuf()->in_avail() != 0) {
        // cout << ">>" << ss.rdbuf()->in_avail() << '\n';
        ss >> temp;
        ss >> num;
        st.insert(num);
    }
    auto iter = st.begin();
    cout << *(iter ++);
    for (; iter != st.end(); iter ++) {
        cout << '+' << *iter;
    }
    cout << '\n';

    return 0;
}
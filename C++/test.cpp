#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL));
    set<int> st;
    for (int i = 0; i < 10; i ++) {
        st.insert(rand());
    }
    return 0;
}
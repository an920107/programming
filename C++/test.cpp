#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int> vec;
    vec.emplace_back(0);
    vec.emplace_back(1);
    vec.emplace_back(2);
    vec.emplace_back(3);

    auto iter = vec.begin();
    auto iterEnd = vec.end();

    while (true) {

        if ((++iter) == iterEnd) break;
        cout << *iter << endl;
    }



    return 0;
}
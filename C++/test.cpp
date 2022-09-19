#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL));
    vector<int> vec{1, 4, 3};
    while (!vec.empty()) {
        int rnd = rand() % vec.size();
        cout << vec[rnd] << '\n';
        vec.erase(vec.begin() + rnd);
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void genNewCode(vector<string> &vec){
    for (int i = vec.size() - 1; i >= 0; i --) {
        vec.push_back("1" + vec[i]);
        vec[i] = "0" + vec[i];
    }
}

int main() {
    vector<string> vec = {"0", "1"};
    int n;
    cin >> n;
    for (int i = 1; i < n; i ++)
        genNewCode(vec);
    for (int i = 0; i < vec.size(); i ++)
        cout << vec[i] << '\n';
    return 0;
}

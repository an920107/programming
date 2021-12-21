#include <bits/stdc++.h>
using namespace std;

vector<string> GenVec(vector<string> vec);

int main() {
    vector<string> vec = {"0", "1"};
    int n;
    cin >> n;
    for (int i = 1; i < n; i ++) {
        vec = GenVec(vec);
    }
    for (int j = 0; j < vec.size(); j ++) {
        cout << vec[j] << '\n';
    }
    return 0;
}

vector<string> GenVec(vector<string> vec) {
    for (int i = vec.size() - 1; i >= 0; i --) {
        vec.push_back("1" + vec[i]);
        vec[i] = "0" + vec[i];
    }
    return vec;
}

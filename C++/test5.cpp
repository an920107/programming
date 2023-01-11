#include <bits/stdc++.h>

using namespace std;

int getMid(vector<int> vec) {
    sort(vec.begin(), vec.end());
    return vec[vec.size() / 2];
}

int func(vector<int> vecX, vector<int> vecY) {
    int midX = getMid(vecX);
    int midY = getMid(vecY);

    int distanceX = __INT32_MAX__, distanceY = __INT32_MAX__;
    for (auto &n : vecY) {
        distanceY += n;
    }
    sort(vecX.begin(), vecX.end());
    
}

int main() {
    
    return 0;
}
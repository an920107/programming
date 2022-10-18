#include <bits/stdc++.h>
using namespace std;

template<typename Func>
clock_t getRunTime(Func &lambda) {
    clock_t start = clock();
    lambda();
    clock_t end = clock();
    return end - start;
}

vector<int> vec;

auto forI = [](void) {
    for (int i = vec.size() - 1; i >= 0; i --)
        printf("%d", vec[i]);
};

auto forIter = [](void) {
    for (auto iter = vec.rbegin(); iter != vec.rend(); iter ++)
        printf("%d", *iter);
};

auto forEach = [](void) {
    reverse(vec.begin(), vec.end());
    for (auto &n : vec)
        printf("%d", n);
};

int main() {

    for (int i = 0; i < 1E6; i ++) {
        vec.emplace_back(i);
        printf("%d\n", i);
    }

    double forITime(getRunTime(forI) / 100.0);
    double forIterTime(getRunTime(forIter) / 100.0);
    double forEachTime(getRunTime(forEach) / 100.0);

    printf("\n");
    printf("For i   : %.4lf ms\n", forITime);
    printf("For iter: %.4lf ms\n", forIterTime);
    printf("For each: %.4lf ms\n", forEachTime);

    return 0;
}
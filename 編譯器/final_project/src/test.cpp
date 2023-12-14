#include <bits/stdc++.h>
#include "include/python.hpp"
using namespace std;

int main() {
    Python py;
    py.commit("for i in range(1, 10):");
    py.commit(" if i % 2 == 0:");
    py.commit("  print(f'count {i}')");
    cout << py.exec();
    return 0;
}

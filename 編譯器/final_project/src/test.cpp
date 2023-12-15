#include <iostream>
#include <unordered_map>
#include <unordered_map>
#include "include/util.hpp"
using namespace std;

int main() {
    string str = ",12,-23,111,2334,";
    for (auto s : split(str, ",")) {
        cout << s << "~\n";
    }
    return 0;
}

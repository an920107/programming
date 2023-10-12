#include <bits/stdc++.h>
using namespace std;

enum Type { A, B, C };

template <typename T>
class Enum {
   private:
    T value;

   public:
    enum X = T;

    Enum() = default;
    Enum(T value) : value(value) {}
};

int main() { return 0; }
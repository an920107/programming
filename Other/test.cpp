#include <bits/stdc++.h>
#include "BigNumber.h"
#include "Fraction.h"
using namespace std;

int main() {
    Fraction x = Fraction(1, 2), y = Fraction(2, 3);
    x = x + y;
    cout << x.numerator << x.denominator;
    
    return 0;
}

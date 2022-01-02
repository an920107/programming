#include <iostream>
#include <cmath>

class Fraction {
private:
    friend int gcd(int, int);
    void reduce(Fraction&);
    
public:
    int numerator, denominator;
    Fraction();
    Fraction(int);
    Fraction(int, int);
    Fraction operator+(Fraction);
    Fraction operator-(Fraction);
    Fraction operator*(Fraction);
    Fraction operator/(Fraction);
    bool operator>(Fraction);
    bool operator<(Fraction);
    bool operator==(Fraction);
    bool operator!=(Fraction);
    bool operator>=(Fraction);
    bool operator<=(Fraction);
};

Fraction::Fraction() {
    *this = Fraction(0, 1);
}

Fraction::Fraction(int n) {
    *this = Fraction(n, 1);
}

Fraction::Fraction(int n, int d) {
    numerator = n;
    denominator = d;
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
    reduce(*this);
}

int gcd(int x, int y) {
    if (y == 0) return abs(x);
    return gcd(y, x % y);
}

void Fraction::reduce(Fraction &obj) {
    int _gcd = gcd(obj.numerator, obj.denominator);
    obj.numerator /= _gcd;
    obj.denominator /= _gcd;
}

Fraction Fraction::operator+(Fraction obj) {
    Fraction res = *this;
    res.numerator = res.numerator * obj.denominator +
        obj.numerator * res.denominator;
    res.denominator *= obj.denominator;
    reduce(res);
    return res;
}

Fraction Fraction::operator-(Fraction obj) {
    Fraction res = *this;
    res.numerator = res.numerator * obj.denominator -
        obj.numerator * res.denominator;
    res.denominator *= obj.denominator;
    reduce(res);
    return res;
}

Fraction Fraction::operator*(Fraction obj) {
    Fraction res = *this;
    res.numerator *= obj.numerator;
    res.denominator *= obj.denominator;
    reduce(res);
    return res;
}

Fraction Fraction::operator/(Fraction obj) {
    Fraction res = *this;
    res.numerator *= obj.denominator;
    res.denominator *= obj.numerator;
    reduce(res);
    return res;
}

bool Fraction::operator>(Fraction obj) {
    Fraction tmp = *this;
    tmp.numerator *= obj.denominator;
    obj.numerator *= tmp.denominator;
    return tmp.numerator > obj.numerator;
}

bool Fraction::operator<(Fraction obj) {
    Fraction tmp = *this;
    tmp.numerator *= obj.denominator;
    obj.numerator *= tmp.denominator;
    return tmp.numerator < obj.numerator;
}

bool Fraction::operator==(Fraction obj) {
    Fraction tmp = *this;
    tmp.numerator *= obj.denominator;
    obj.numerator *= tmp.denominator;
    return tmp.numerator == obj.numerator;
}

bool Fraction::operator!=(Fraction obj) {
    Fraction tmp = *this;
    tmp.numerator *= obj.denominator;
    obj.numerator *= tmp.denominator;
    return tmp.numerator != obj.numerator;
}

bool Fraction::operator>=(Fraction obj) {
    Fraction tmp = *this;
    tmp.numerator *= obj.denominator;
    obj.numerator *= tmp.denominator;
    return tmp.numerator >= obj.numerator;
}

bool Fraction::operator<=(Fraction obj) {
    Fraction tmp = *this;
    tmp.numerator *= obj.denominator;
    obj.numerator *= tmp.denominator;
    return tmp.numerator <= obj.numerator;
}

#include <bits/stdc++.h>
using namespace std;

#define int128 __int128_t

class Fraction {
private:
    int128 numerator, denominator;
    int128 gcd(int128, int128);
    void reduce();


public:
    Fraction();
    Fraction(int128, int128);
    int128 getNumerator();
    int128 getDenominator();
    int128 getWholeNumber();

    void reciprocal();
    void removeWholeNumber();
};

int128 readInt128();
void printInt128(const int128&);
string intToStrAndReverse(int128);
void solve(int128&, int128&);

int main() {
    int t = 0;
    int128 p, q;
    while (true) {
        p = readInt128();
        q = readInt128();
        if (!(p | q)) break;
        cout << "Case " << (++ t) << ":\n";
        solve(p, q);
    }
    return 0;
}

void solve(int128 &p, int128 &q) {
    printInt128(p);
    cout << " / ";
    printInt128(q);
    cout << '\n';
    Fraction frac(p, q);
    vector<int128> vec;
    while (frac.getDenominator() > 1) {
        vec.emplace_back(frac.getWholeNumber());
        frac.removeWholeNumber();
        frac.reciprocal();
    }
    vec.emplace_back(frac.getNumerator() - 1);
    vector<string> result;
    result.emplace_back("1");
    reverse(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i ++) {
        result.emplace_back("-");
        while (result.back().length() < result[0].length())
            result.back() += '-';
        result.back() += ".+." + intToStrAndReverse(vec[i]);
        result.emplace_back("");
        for (int j = result[0].length() / 2; j > 0; j --)
            result.back() += '.';
        result.back() += '1';
        for (int j = 0; j < i * 2 + 1; j ++)
            while (result[j].length() < result[i * 2 + 1].length())
                result[j] += '.';
    }
    while (result.back().length() < result[0].length())
        result.back() += '.';
    reverse(result.begin(), result.end());
    for (auto &str : result) {
        reverse(str.begin(), str.end());
        cout << str << '\n';
    }
}

int128 readInt128() {
    int128 num = 0;
    char ch;
    while (ch = getchar()) {
        if (ch == ' ' || ch == '\n')
            break;
        num = num * 10 + ch - '0';
    }
    return num;
}

void printInt128(const int128 &num) {
    if (num >= 10)
        printInt128(num / 10);
    putchar(num % 10 + '0');
}

string intToStrAndReverse(int128 num) {
    string str = "";
    while (num) {
        str += (char)(num % 10 + '0');
        num /= 10;
    }
    return str;
}

Fraction::Fraction() : numerator(1), denominator(1) {}

Fraction::Fraction(int128 num, int128 den) :
    numerator(num), denominator(den) { reduce(); }

int128 Fraction::gcd(int128 x, int128 y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

void Fraction::reduce() {
    int128 _gcd = gcd(numerator, denominator);
    numerator /= _gcd;
    denominator /= _gcd;
}

int128 Fraction::getNumerator() { return numerator; }

int128 Fraction::getDenominator() { return denominator; }

int128 Fraction::getWholeNumber() { return numerator / denominator; }

void Fraction::reciprocal() {
    swap(numerator, denominator);
}

void Fraction::removeWholeNumber() {
    this->numerator %= this->denominator;
}
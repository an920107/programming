#include <bits/stdc++.h>
using namespace std;

typedef long long llong;
const int digits_per_unit = 1;
const llong carry = 1E1;

class BigNumber {
private:

    vector<llong> vec;

    void tidyUp() {
        vec.insert(vec.begin(), 0);
        for (int i = vec.size(); i > 0; i --) {
            if (vec[i] >= carry) {
                vec[i - 1] += vec[i] / carry;
                vec[i] %= carry;
            }
        }
        if (vec[0] == 0)
            vec.erase(vec.begin());
    }

public:

    BigNumber() : vec({0}) {}

    BigNumber(string str) {
        while (!str.empty()) {
            int begin = str.length() - digits_per_unit;
            begin = begin < 0 ? 0 : begin;
            string sub = str.substr(begin, digits_per_unit);
            str = str.substr(0, str.length() - sub.length());
            vec.emplace_back(stoll(sub));
        }
        reverse(vec.begin(), vec.end());
    }

    BigNumber operator+(const BigNumber &x) {
        int thisIndex = vec.size() - 1;
        int xIndex = x.vec.size() - 1;
        BigNumber result;
        result.vec.clear();
        while (thisIndex >= 0 || xIndex >= 0) {
            const llong thisNum = thisIndex >= 0 ? vec[thisIndex --] : 0;
            const llong xNum = xIndex >= 0 ? x.vec[xIndex --] : 0;
            result.vec.emplace_back(thisNum + xNum);
        }
        reverse(result.vec.begin(), result.vec.end());
        result.tidyUp();
        return result;
    }

    BigNumber operator*(const BigNumber &x) {
        BigNumber result;
        for (int i = vec.size() - 1; i >= 0; i --) {
            BigNumber tmp;
            tmp.vec.clear();
            for (int j = x.vec.size() - 1; j >= 0; j --)
                tmp.vec.emplace_back(vec[i] * x.vec[j]);
            reverse(tmp.vec.begin(), tmp.vec.end());
            tmp.tidyUp();
            for (int k = 1; k < vec.size() - i; k ++)
                tmp.vec.emplace_back(0);
            result = result + tmp;
            result.tidyUp();
        }
        return result;
    }

    friend istream& operator>>(istream &is, BigNumber &num) {
        string str;
        is >> str;
        num = BigNumber(str);
        return is;
    }

    friend ostream& operator<<(ostream &os, const BigNumber &num) {
        for (auto &x : num.vec)
            os << x;
        return os;
    }

};

int main() {

    BigNumber x, y, z;
    cin >> x >> y;
    clock_t start = clock();
    for (int i = 0; i < 1; i ++)
        z = x * y;
    clock_t end = clock();
    cout << z << '\n';
    cout << (long long)(double(end - start) / CLOCKS_PER_SEC * 1E9 / 1) << '\n';

    return 0;
}
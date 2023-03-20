#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

class BigNumber {
private:

    vector<llong> numVec;

    void tidyUp() {
        numVec.insert(numVec.begin(), 0);
        for (int i = numVec.size(); i > 0; i --) {
            if (numVec[i] >= (llong)1E9) {
                numVec[i - 1] += numVec[i] / (llong)1E9;
                numVec[i] %= (llong)1E9;
            }
        }
        if (numVec[0] == 0)
            numVec.erase(numVec.begin());
    }

public:

    BigNumber() : numVec({0}) {}

    BigNumber(string str) {
        while (!str.empty()) {
            int begin = str.length() - 9;
            begin = begin < 0 ? 0 : begin;
            string sub = str.substr(begin, 9);
            str = str.substr(0, str.length() - sub.length());
            numVec.emplace_back(stoll(sub));
        }
        reverse(numVec.begin(), numVec.end());
    }

    BigNumber operator+(const BigNumber &x) {
        int thisIndex = numVec.size() - 1;
        int xIndex = x.numVec.size() - 1;
        BigNumber result;
        result.numVec.clear();
        while (thisIndex >= 0 || xIndex >= 0) {
            const llong thisNum = thisIndex >= 0 ? numVec[thisIndex --] : 0;
            const llong xNum = xIndex >= 0 ? x.numVec[xIndex --] : 0;
            result.numVec.emplace_back(thisNum + xNum);
        }
        reverse(result.numVec.begin(), result.numVec.end());
        result.tidyUp();
        return result;
    }

    BigNumber operator*(const BigNumber &x) {
        BigNumber result;
        for (int i = numVec.size() - 1; i >= 0; i --) {
            BigNumber tmp;
            tmp.numVec.clear();
            for (int j = x.numVec.size() - 1; j >= 0; j --)
                tmp.numVec.emplace_back(numVec[i] * x.numVec[j]);
            reverse(tmp.numVec.begin(), tmp.numVec.end());
            tmp.tidyUp();
            for (int k = 1; k < numVec.size() - i; k ++)
                tmp.numVec.emplace_back(0);
            result = result + tmp;
            result.tidyUp();
        }
        return result;
    }

    friend ostream& operator<<(ostream &os, const BigNumber &bign) {
        for (auto &x : bign.numVec)
            os << x;
        return os;
    }

};

int main() {

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    string x, y;
    cin >> x >> y;

    BigNumber numX(x), numY(y);
    cout << numX * numY << '\n';

    return 0;
}
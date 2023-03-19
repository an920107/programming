#include <bits/stdc++.h>
using namespace std;

class Solve {
private:

    vector<int> primes;
    bool buildingPrimes = true;

    bool isPrime(int n) {
        if (buildingPrimes) {
            int n_sqrt = (int)sqrt(n);
            for (auto &x : primes) {
                if (x > n_sqrt)
                    break;
                if (n % x == 0)
                    return false;
            }
            return true;    
        }
        return find(primes.begin(), primes.end(), n) != primes.end();
    }

public:

    Solve() : primes({2}) {
        for (int i = 3; i < 2001; i ++)
            if (isPrime(i))
                primes.emplace_back(i);
        buildingPrimes = false;
    }

    void solve(string &str) {
        map<char, int> count;
        for (auto &c : str)
            count[c] ++;
        bool flag = false;
        for (auto &[key, val] : count)
            if (isPrime(val)) {
                flag = true;
                cout << key;
            }
        if (!flag)
            cout << "empty";
        cout << '\n';
    }

};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solve sol;

    int t;
    cin >> t;
    string str;
    while (t --) {
        cin >> str;
        sol.solve(str);
    }

    return 0;
}
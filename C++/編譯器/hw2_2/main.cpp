#include <bits/stdc++.h>
using namespace std;

class Symbol {
   public:
    enum Type { terminal,
                nonterminal,
                empty,
                eof };

   private:
    char _c;

   public:
    Symbol(char c) : _c(c) {}

    char get() const { return _c; }
    Type type() const {
        if (_c >= 'a' && _c <= 'z')
            return terminal;
        else if (_c >= 'A' && _c <= 'Z')
            return nonterminal;
        else if (_c == ';')
            return empty;
        else if (_c == '$')
            return eof;
        return terminal;
    }

    bool operator==(const Symbol &rhs) const {
        return _c == rhs._c;
    }

    bool operator>(const Symbol &rhs) const {
        return _c > rhs._c;
    }

    bool operator<(const Symbol &rhs) const {
        return _c < rhs._c;
    }
};

class Rule : public vector<vector<Symbol>> {
   public:
    Rule() {}

    Rule(string input) : vector<vector<Symbol>>(1) {
        stringstream ss(input);
        char c;
        while (ss >> c) {
            if (c == '|') {
                this->emplace_back();
            } else {
                this->back().emplace_back(c);
            }
        }
    }
};

typedef map<Symbol, set<Symbol>> FirstSet;

class Grammer : public map<Symbol, Rule> {
   public:
    Grammer() {}

    FirstSet first_set() const {
        FirstSet result;
        for (auto &p : *this) {
            auto nonterminal_symbol = p.first;

            function<void(Symbol)> dfs = [&](Symbol key) {
                for (auto &sequence : this->at(key)) {
                    auto first_symbol = sequence.front();
                    if (first_symbol.type() == Symbol::nonterminal) {
                        dfs(first_symbol);
                        for (auto &symbol : result[first_symbol])
                            result[key].insert(symbol);
                    } else {
                        result[key].insert(first_symbol);
                    }
                }
            };

            dfs(nonterminal_symbol);
        }
        return result;
    }
};

int main() {
    string input;
    Grammer grammer;
    while (getline(cin, input)) {
        if (input == "END_OF_GRAMMAR") break;
        grammer[Symbol(input[0])] = Rule(input.substr(2));
    }
    for (auto &p : grammer.first_set()) {
        cout << p.first.get() << " ";
        for (auto &c : p.second) cout << c.get();
        cout << "\n";
    }
    cout << "END_OF_FIRST\n";
    return 0;
}
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
            vector<Symbol> current_set;
            current_set.clear();

            function<void(Symbol)> dfs = [&](Symbol key) {
                for (auto &sequence : this->at(key)) {
                    for (auto iter = sequence.begin(); iter != sequence.end(); iter++) {
                        // 如果是 non terminal
                        if (iter->type() == Symbol::nonterminal) {
                            // 用 dfs 尋找 non terminal 的 first set
                            dfs(*iter);
                            // 如果 non terminal 的 first set 最後是 empty
                            if (current_set.back().type() == Symbol::empty) {
                                // 如果已經迭代到底了
                                if (iter != sequence.end() - 1)
                                    // 移除最後的 empty symbol
                                    current_set.pop_back();
                            // 否則結束迭代
                            } else break;
                        // 如果是 terminal
                        } else {
                            // 將 terminal 加入 current_set
                            current_set.push_back(*iter);
                            // 結束迭代 symbol sequence
                            break;
                        }
                    }
                }
            };
            dfs(nonterminal_symbol);
            result[nonterminal_symbol].insert(current_set.begin(), current_set.end());
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
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

int main() {
    set<Symbol> s;
    s.insert(Symbol(';'));
    s.insert(Symbol('$'));
    s.erase(Symbol('a'));

    return 0;
}
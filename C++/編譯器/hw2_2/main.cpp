#include <bits/stdc++.h>
using namespace std;

class Character {
   public:
    enum Type { terminal, nonterminal, eos, eof };

   private:
    char _c;
    Type _type;

   public:
    Character(char c) : _c(c) {
        if (_c >= 'a' && _c <= 'z')
            _type = terminal;
        else if (_c >= 'A' && _c <= 'Z')
            _type = nonterminal;
        else if (_c == ';')
            _type = eos;
        else if (_c == '$')
            _type = eof;
    }

    char get() const { return _c; }
    Type type() const { return _type; }

    bool operator==(const Character &rhs) const {
        return _c == rhs._c && _type == rhs._type;
    }

    bool operator>(const Character &rhs) const {
        return _c > rhs._c || (_c == rhs._c && _type > rhs._type);
    }

    bool operator<(const Character &rhs) const {
        return _c < rhs._c || (_c == rhs._c && _type < rhs._type);
    }
};

class Rule : public vector<vector<Character>> {
   public:
    Rule() {}

    Rule(string input) : vector<vector<Character>>(1) {
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

typedef map<Character, set<Character>> FirstSet;

class Grammer : public map<Character, Rule> {
   public:
    Grammer() {}

    FirstSet first_set() const {
        FirstSet result;
        for (auto &p : *this) {
            auto first_char_set = p.second.front();
            function<void(Character)> find_first = [&](Character key) {
                for (auto &value : this->at(key)) {
                    if (value.front().type() == Character::nonterminal) {
                        find_first(value.front());
                    } else {
                        result[p.first].insert(value.front());
                    }
                }
            };
            find_first(p.first);
        }
        return result;
    }
};

int main() {
    string input;
    Grammer grammer;
    while (getline(cin, input)) {
        if (input == "END_OF_GRAMMAR") break;
        grammer[Character(input[0])] = Rule(input.substr(2));
    }
    for (auto &p : grammer.first_set()) {
        cout << p.first.get() << " ";
        for (auto &c : p.second) cout << c.get();
        cout << "\n";
    }
    cout << "END_OF_FIRST\n";
    return 0;
}
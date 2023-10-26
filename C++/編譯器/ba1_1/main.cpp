#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

/**
 * TOKEN DECLARATIONS
 */

class Token {
   public:
    enum Values { NUM, IDENTIFIER, SYMBOL, KEYWORD, SPACE };

   public:
    Values value;
    Token(Values value);
    Token() = default;

    string to_string() const;
};

namespace TokenSetting {
static const map<Token::Values, string> strings{
    {Token::NUM, "NUM"},       {Token::Values::IDENTIFIER, "IDENTIFIER"},
    {Token::SYMBOL, "SYMBOL"}, {Token::Values::KEYWORD, "KEYWORD"},
    {Token::SPACE, "SPACE"},
};
}  // namespace TokenSetting

/**
 * INPUT_STREAM DECLARATION
 */

class InputStream : public string {
   private:
    string match;

    bool is_space(int index) const;

   public:
    InputStream(const string&);
    InputStream() = default;

    string peep(const Token&);
    bool check(const Token&);
    void pop(const Token&);
    bool empty() const;
    const string& to_string() const;
};

/**
 * PARSER DECLARATION
 */

class Parser {
   private:
    string text;
    vector<string> result;

    void process(InputStream&, const Token&);

    void program(InputStream&);
    void stmts(InputStream&);
    void stmt(InputStream&);
    void primary(InputStream&);
    void primary_tail(InputStream&);

   public:
    Parser(const string&);
    Parser();

    vector<string> parse();
};

/**
 * MAIN
 */

int main() {
    string line;
    while (getline(cin, line)) {
        try {
            for (auto parsed : Parser(line).parse()) cout << parsed << "\n";
        } catch (const exception& e) {
            cout << "ERROR\n";
        }
    }
    return 0;
}

/**
 * TOKEN DEFINITIONS
 */

Token::Token(Values value) : value(value) {}

string Token::to_string() const {
    auto iter = TokenSetting::strings.find(this->value);
    return iter == TokenSetting::strings.end() ? "" : iter->second;
}

/**
 * INPUT_STREAM DEFINITIONS
 */

InputStream::InputStream(const string& text) : string(text) {}

bool InputStream::is_space(int index) const {
    if (index >= this->length()) return true;
    char c = (*this)[index];
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r') return true;
    return false;
}

string InputStream::peep(const Token& token) {
    this->match = "";
    while (this->is_space(0)) {
        *this = this->substr(1);
        if (this->empty()) return "";
    }
    InputStream tmp = *this;
    if (token.value == Token::NUM) {
        if (tmp[0] == '0')
            this->match = "0";
        else if (tmp[0] >= '1' && tmp[0] <= '9') {
            for (int i = 1;; i++) {
                if (tmp.is_space(i)) {
                    this->match = tmp.substr(0, i);
                    break;
                }
                if (!(tmp[i] >= '0' && tmp[i] <= '9')) {
                    this->match = tmp.substr(0, i);
                    break;
                }
            }
        }
    } else if (token.value == Token::IDENTIFIER) {
        if ((tmp[0] >= 'A' && tmp[0] <= 'Z') ||
            (tmp[0] >= 'a' && tmp[0] <= 'z')) {
            if (tmp.is_space(1))
                this->match = tmp.substr(0, 1);
            else {
                for (int i = 1;; i++) {
                    if (tmp.is_space(i)) {
                        this->match = tmp.substr(0, i);
                        break;
                    }
                    if (!((tmp[i] >= 'A' && tmp[i] <= 'Z') ||
                          (tmp[i] >= 'a' && tmp[i] <= 'z') ||
                          (tmp[i] >= '0' && tmp[i] <= '9'))) {
                        this->match = tmp.substr(0, i);
                        break;
                    }
                }
            }
        }
    } else if (token.value == Token::SYMBOL) {
        vector<char> symbols{'+', '-', '*', '/', '=', '(',
                             ')', '{', '}', '<', '>', ';'};
        for (auto s : symbols)
            if (tmp[0] == s) {
                this->match = tmp.substr(0, 1);
                break;
            }
    } else if (token.value == Token::KEYWORD) {
        if (tmp.length() >= 2 && tmp.substr(0, 2) == "if")
            this->match = "if";
        else if (tmp.length() >= 4 && tmp.substr(0, 4) == "else")
            this->match = "else";
        else if (tmp.length() >= 5 && tmp.substr(0, 5) == "while")
            this->match = "while";
    }
    return this->match;
}

bool InputStream::check(const Token& token) {
    return !this->peep(token).empty();
}

void InputStream::pop(const Token& token) {
    *this = this->substr(this->match.length());
}

bool InputStream::empty() const { return string::empty(); }

const string& InputStream::to_string() const { return *this; }

/**
 * PARSER DEFINITIONS
 */

Parser::Parser(const string& text) : text(text) {}

Parser::Parser() : Parser("") {}

vector<string> Parser::parse() {
    this->result.clear();
    InputStream input(this->text);
    this->program(input);
    return this->result;
}

void Parser::process(InputStream& input, const Token& token) {
    this->result.push_back(token.to_string() + " \"" + input.peep(token) +
                           "\"");
    input.pop(token);
}

///

void Parser::program(InputStream& input) {
    this->stmts(input);
    if (!input.empty()) throw exception();
}

void Parser::stmts(InputStream& input) {
    if (!input.empty()) {
        this->stmt(input);
        this->stmts(input);
    }
}

void Parser::stmt(InputStream& input) {
    if (input.check(Token::NUM)) {
        this->process(input, Token::NUM);
    } else if (input.check(Token::KEYWORD)) {
        this->process(input, Token::KEYWORD);
    } else if (input.check(Token::IDENTIFIER)) {
        this->process(input, Token::IDENTIFIER);
    } else if (input.check(Token::SYMBOL)) {
        this->process(input, Token::SYMBOL);
    } else {
        this->result.push_back("Invalid");
        input = input.substr(1);
    }
}
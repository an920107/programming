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
    enum Values {
        ID,
        NATIONNUM,
        PHONENUM,
        YEAR,
        MONTH,
        DAY,
        PLUS,
        DOT,
        LBR,
        RBR,
        SLASH
    };

   public:
    Values value;
    Token(Values value);
    Token() = default;

    string to_string() const;
};

namespace TokenSetting {
static const map<Token::Values, string> strings{
    {Token::ID, "ID"},
    {Token::NATIONNUM, "NATIONNUM"},
    {Token::PHONENUM, "PHONENUM"},
    {Token::YEAR, "YEAR"},
    {Token::MONTH, "MONTH"},
    {Token::DAY, "DAY"},
    {Token::PLUS, "PLUS"},
    {Token::DOT, "DOT"},
    {Token::LBR, "LBR"},
    {Token::RBR, "RBR"},
    {Token::SLASH, "SLASH"},
};
}  // namespace TokenSetting

/**
 * INPUT_STREAM DECLARATION
 */

class InputStream : public string {
   private:
    string match;

    bool is_space(int) const;
    bool is_num_in(int, int) const;

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
    void stmt(InputStream&);
    void phone(InputStream&);
    void date(InputStream&);

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
            cout << "Invalid input\n";
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

bool InputStream::is_num_in(int begin, int length) const {
    for (int i = 1; i < begin + length; i++) {
        char c = (*this)[i];
        if (!(c >= '0' && c <= '9')) return false;
    }
    return true;
}

string InputStream::peep(const Token& token) {
    this->match = "";
    while (this->is_space(0)) {
        *this = this->substr(1);
        if (this->empty()) return "";
    }
    InputStream tmp = *this;
    if (token.value == Token::ID) {
        if (tmp.length() >= 10 && tmp[0] >= 'A' && tmp[0] <= 'Z') {
            if (this->is_num_in(1, 9)) this->match = tmp.substr(0, 10);
        }
    } else if (token.value == Token::NATIONNUM) {
        if (tmp.length() >= 3) {
            if (this->is_num_in(0, 3)) this->match = tmp.substr(0, 3);
        }
    } else if (token.value == Token::PHONENUM) {
        if (tmp.length() >= 9 && tmp[0] == '9') {
            if (this->is_num_in(1, 8)) this->match = tmp.substr(0, 9);
        }
    } else if (token.value == Token::YEAR) {
        if (tmp.length() >= 4 && (tmp[0] == '1' || tmp[0] == '2')) {
            if (this->is_num_in(1, 3)) this->match = tmp.substr(0, 4);
        }
    } else if (token.value == Token::MONTH) {
        if (tmp.length() >= 3) {
            InputStream sub = tmp.substr(0, 3);
            vector<string> mons{"JAN", "FEB", "MAR", "JAN", "FEB",
                                "MAR", "APR", "MAY", "JUN", "JUL",
                                "AUG", "SEP", "OCT", "NOV", "DEC"};
            for (auto s : mons) {
                if (sub == s) {
                    this->match = sub;
                    break;
                }
            }
        }
    } else if (token.value == Token::DAY) {
        if (tmp.length() >= 2) {
            if ((tmp[0] == '1' || tmp[0] == '2') &&
                (tmp[1] >= '0' && tmp[1] <= '9')) {
                this->match = tmp.substr(0, 2);
            } else if (tmp.substr(0, 2) == "30" || tmp.substr(0, 2) == "31") {
                this->match = tmp.substr(0, 2);
            }
        } else if (tmp[0] >= '1' && tmp[0] <= '9') {
            this->match = tmp.substr(0, 1);
        }
    } else if (token.value == Token::PLUS) {
        if (tmp[0] == '+') this->match = "+";
    } else if (token.value == Token::DOT) {
        if (tmp[0] == '.') this->match = ".";
    } else if (token.value == Token::LBR) {
        if (tmp[0] == '(') this->match = "(";
    } else if (token.value == Token::RBR) {
        if (tmp[0] == ')') this->match = ")";
    } else if (token.value == Token::SLASH) {
        if (tmp[0] == '/') this->match = "/";
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
    this->result.push_back(input.peep(token) + " " + token.to_string());
    input.pop(token);
}

///

void Parser::program(InputStream& input) {
    this->stmt(input);
    if (!input.empty()) throw exception();
}

void Parser::stmt(InputStream& input) {
    if (input.check(Token::ID)) {
        this->process(input, Token::ID);
    } else if (input.check(Token::PLUS)) {
        this->phone(input);
    } else if (input.check(Token::MONTH) || input.check(Token::YEAR)) {
        this->date(input);
    }
}

void Parser::phone(InputStream& input) {
    if (input.check(Token::PLUS)) {
        this->process(input, Token::PLUS);
        if (input.check(Token::LBR)) {
            this->process(input, Token::LBR);
            if (input.check(Token::NATIONNUM)) {
                this->process(input, Token::NATIONNUM);
                if (input.check(Token::RBR)) {
                    this->process(input, Token::RBR);
                    if (input.check(Token::PHONENUM)) {
                        this->process(input, Token::PHONENUM);
                    }
                }
            }
        }
    }
}

void Parser::date(InputStream& input) {
    if (input.check(Token::MONTH)) {
        this->process(input, Token::MONTH);
        if (input.check(Token::DOT)) {
            this->process(input, Token::DOT);
            if (input.check(Token::DAY)) {
                this->process(input, Token::DAY);
                if (input.check(Token::DOT)) {
                    this->process(input, Token::DOT);
                    if (input.check(Token::YEAR)) {
                        this->process(input, Token::YEAR);
                    }
                }
            }
        }
    } else if (input.check(Token::YEAR)) {
        this->process(input, Token::YEAR);
        if (input.check(Token::SLASH)) {
            this->process(input, Token::SLASH);
            if (input.check(Token::MONTH)) {
                this->process(input, Token::MONTH);
                if (input.check(Token::SLASH)) {
                    this->process(input, Token::SLASH);
                    if (input.check(Token::DAY)) {
                        this->process(input, Token::DAY);
                    }
                }
            }
        }
    }
}

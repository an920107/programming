#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>
using namespace std;

/**
 * TOKEN DECLARATIONS
 */

class Token {
   public:
    enum Values { ID, STRLIT, LBR, RBR, DOT, SPACE };

   private:
    Values value;

   public:
    Token(Values value);
    Token() = default;

    regex to_regex() const;
    string to_string() const;
};

namespace TokenSetting {
static const map<Token::Values, regex> regexs{
    {Token::ID, regex("^ *[A-Za-z_][A-Za-z0-9_]*")},
    {Token::STRLIT, regex("^ *\"[^\"]*\"")},
    {Token::LBR, regex("^ *\\(")},
    {Token::RBR, regex("^ *\\)")},
    {Token::DOT, regex("^ *\\.")},
    {Token::SPACE, regex("^ *")},
};
static const map<Token::Values, string> strings{
    {Token::ID, "ID"},   {Token::Values::STRLIT, "STRLIT"},
    {Token::LBR, "LBR"}, {Token::Values::RBR, "RBR"},
    {Token::DOT, "DOT"}, {Token::SPACE, "SPACE"},
};
}  // namespace TokenSetting

/**
 * INPUT_STREAM DECLARATION
 */

class InputStream : private string {
   public:
    InputStream(const string&);
    InputStream() = default;

    string peep(const Token&) const;
    bool check(const Token&) const;
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
            cout << "invalid input\n";
        }
    }
    return 0;
}

/**
 * TOKEN DEFINITIONS
 */

Token::Token(Values value) : value(value) {}

regex Token::to_regex() const {
    auto iter = TokenSetting::regexs.find(this->value);
    return iter == TokenSetting::regexs.end() ? regex() : iter->second;
}

string Token::to_string() const {
    auto iter = TokenSetting::strings.find(this->value);
    return iter == TokenSetting::strings.end() ? "" : iter->second;
}

/**
 * INPUT_STREAM DEFINITIONS
 */

InputStream::InputStream(const string& text) : string(text) {}

string InputStream::peep(const Token& token) const {
    smatch match;
    regex_search(*this, match, token.to_regex());
    return match.str();
}

bool InputStream::check(const Token& token) const {
    return !this->peep(token).empty();
}

void InputStream::pop(const Token& token) {
    *this = regex_replace(*this, token.to_regex(), "");
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
    input.pop(Token::SPACE);
    this->result.push_back(token.to_string() + " " + input.peep(token));
    input.pop(token);
}

///

void Parser::program(InputStream& input) {
    this->stmts(input);
    if (!input.empty()) throw exception();
}

void Parser::stmts(InputStream& input) {
    if (input.check(Token::STRLIT) || input.check(Token::ID)) {
        this->stmt(input);
        this->stmts(input);
    }
}

void Parser::stmt(InputStream& input) {
    if (input.check(Token::STRLIT)) {
        this->process(input, Token::STRLIT);
    } else if (input.check(Token::ID)) {
        this->primary(input);
    }
}

void Parser::primary(InputStream& input) {
    if (input.check(Token::ID)) {
        this->process(input, Token::ID);
        this->primary_tail(input);
    } else {
        throw exception();
    }
}

void Parser::primary_tail(InputStream& input) {
    if (input.check(Token::DOT)) {
        this->process(input, Token::DOT);
        if (input.check(Token::ID)) {
            this->process(input, Token::ID);
            this->primary_tail(input);
        } else {
            throw exception();
        }
    } else if (input.check(Token::LBR)) {
        this->process(input, Token::LBR);
        this->stmt(input);
        if (input.check(Token::RBR)) {
            this->process(input, Token::RBR);
            this->primary_tail(input);
        } else {
            throw exception();
        }
    }
}

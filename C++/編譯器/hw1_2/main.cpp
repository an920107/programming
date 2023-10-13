#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <string>
#include <vector>
using namespace std;

/**
 * TOKEN DECLARATIONS
 */

class Token {
   public:
    enum Values { NUM, PLUS, MINUS, MUL, DIV, LPR, RPR, SPACE };

   private:
    Values value;

   public:
    Token(Values value);
    Token() = default;

    regex to_regex() const;
    string to_string() const;
    bool is_str_required() const;
};

namespace TokenSetting {
static const map<Token::Values, regex> regexs = {
    {Token::NUM, regex("^\\s*(([1-9][0-9]*)|0)")},
    {Token::PLUS, regex("^\\s*\\+")},
    {Token::MINUS, regex("^\\s*\\-")},
    {Token::MUL, regex("^\\s*\\*")},
    {Token::DIV, regex("^\\s*\\/")},
    {Token::LPR, regex("^\\s*\\(")},
    {Token::RPR, regex("^\\s*\\)")},
    {Token::SPACE, regex("^\\s*")},
};
static const map<Token::Values, string> strings = {
    {Token::NUM, "NUM"},     {Token::Values::PLUS, "PLUS"},
    {Token::MINUS, "MINUS"}, {Token::Values::MUL, "MUL"},
    {Token::DIV, "DIV"},     {Token::LPR, "LPR"},
    {Token::RPR, "RPR"},     {Token::SPACE, "SPACE"},
};
static const set<Token::Values> str_requires = {
    {Token::NUM},
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

   public:
    Parser(const string&);
    Parser();

    vector<string> parse();
};

/**
 * MAIN
 */

int main() {
    string line, text;
    while (getline(cin, line)) text += line;
    for (auto parsed : Parser(text).parse()) cout << parsed << "\n";
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

bool Token::is_str_required() const {
    return TokenSetting::str_requires.find(this->value) !=
           TokenSetting::str_requires.end();
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
    this->result.push_back(token.to_string() + (token.is_str_required()
                                                    ? " " + input.peep(token)
                                                    : ""));
    input.pop(token);
}

///

void Parser::program(InputStream& input) { this->stmts(input); }

void Parser::stmts(InputStream& input) {
    if (!input.empty()) {
        this->stmt(input);
        this->stmts(input);
    }
}

void Parser::stmt(InputStream& input) {
    if (input.check(Token::NUM)) {
        this->process(input, Token::NUM);
    } else if (input.check(Token::PLUS)) {
        this->process(input, Token::PLUS);
    } else if (input.check(Token::MINUS)) {
        this->process(input, Token::MINUS);
    } else if (input.check(Token::MUL)) {
        this->process(input, Token::MUL);
    } else if (input.check(Token::DIV)) {
        this->process(input, Token::DIV);
    } else if (input.check(Token::LPR)) {
        this->process(input, Token::LPR);
    } else if (input.check(Token::RPR)) {
        this->process(input, Token::RPR);
    }
}

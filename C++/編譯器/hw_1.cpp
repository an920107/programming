#include <bits/stdc++.h>
using namespace std;

/**
 * DECLARATIONS
 */

class Token {
   public:
    enum class Values { ID, STRLIT, LBR, RBR, DOT };

   private:
    Values value;

   public:
    Token(Values value);
    Token() = default;

    regex to_regex() const;
    string to_string() const;

    bool in(const string&) const;
    void remove_in(string&) const;
    smatch search_in(const string&) const;
};

namespace Tokens {
static const unordered_map<Token::Values, regex> regexs{
    {Token::Values::ID, regex("^[A-Za-z_][A-Za-z0-9_]*")},
    {Token::Values::STRLIT, regex("^\"[^\"]*\"")},
    {Token::Values::LBR, regex("^\\(")},
    {Token::Values::RBR, regex("^\\)")},
    {Token::Values::DOT, regex("^\\.")},
};
static const unordered_map<Token::Values, string> strings{
    {Token::Values::ID, "ID"},   {Token::Values::STRLIT, "STRLIT"},
    {Token::Values::LBR, "LBR"}, {Token::Values::RBR, "RBR"},
    {Token::Values::DOT, "DOT"},
};
static const Token ID(Token::Values::ID);
static const Token STRLIT(Token::Values::STRLIT);
static const Token LBR(Token::Values::LBR);
static const Token RBR(Token::Values::RBR);
static const Token DOT(Token::Values::DOT);
}  // namespace Tokens

class Parser {
   private:
    string text;
    vector<string> result;

    void process(string&, Token);

    void program(string&);
    void stmts(string&);
    void stmt(string&);
    void primary(string&);
    void primary_tail(string&);

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
    auto iter = Tokens::regexs.find(this->value);
    return iter == Tokens::regexs.end() ? regex() : iter->second;
}

string Token::to_string() const {
    auto iter = Tokens::strings.find(this->value);
    return iter == Tokens::strings.end() ? "" : iter->second;
}

inline bool Token::in(const string& text) const {
    return !this->search_in(text).empty();
}

inline void Token::remove_in(string& text) const {
    text = regex_replace(text, this->to_regex(), "");
}

smatch Token::search_in(const string& text) const {
    smatch match;
    regex_search(text, match, this->to_regex());
    return match;
}

/**
 * PARSER DEFINITIONS
 */

Parser::Parser(const string& text) : text(text) {}

Parser::Parser() : Parser("") {}

vector<string> Parser::parse() {
    this->result.clear();
    string text(this->text);
    this->program(text);
    return this->result;
}

void Parser::process(string& text, Token token) {
    auto match = token.search_in(text);
    this->result.push_back(token.to_string() + " " + match.str());
    token.remove_in(text);
}

void Parser::program(string& text) {
    this->stmts(text);
    if (!text.empty()) throw exception();
}

void Parser::stmts(string& text) {
    if (Tokens::STRLIT.in(text) || Tokens::ID.in(text)) {
        this->stmt(text);
        this->stmts(text);
    }
}

void Parser::stmt(string& text) {
    if (Tokens::STRLIT.in(text)) {
        this->process(text, Tokens::STRLIT);
    } else if (Tokens::ID.in(text)) {
        this->primary(text);
    }
}

void Parser::primary(string& text) {
    if (Tokens::ID.in(text)) {
        this->process(text, Tokens::ID);
        this->primary_tail(text);
    } else {
        throw exception();
    }
}

void Parser::primary_tail(string& text) {
    if (Tokens::DOT.in(text)) {
        this->process(text, Tokens::DOT);
        if (Tokens::ID.in(text)) {
            this->process(text, Tokens::ID);
            this->primary_tail(text);
        } else {
            throw exception();
        }
    } else if (Tokens::LBR.in(text)) {
        this->process(text, Tokens::LBR);
        this->stmt(text);
        if (Tokens::RBR.in(text)) {
            this->process(text, Tokens::RBR);
            this->primary_tail(text);
        } else {
            throw exception();
        }
    }
}

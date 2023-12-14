#include "parser.hpp"

#include "parse_exception.hpp"

Parser::Parser(const std::string& text) : text(text) {}

Parser::Parser() : Parser("") {}

std::vector<std::string> Parser::parse() {
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
    if (!input.empty()) throw ParseException();
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
        throw ParseException();
    }
}

void Parser::primary_tail(InputStream& input) {
    if (input.check(Token::DOT)) {
        this->process(input, Token::DOT);
        if (input.check(Token::ID)) {
            this->process(input, Token::ID);
            this->primary_tail(input);
        } else {
            throw ParseException();
        }
    } else if (input.check(Token::LBR)) {
        this->process(input, Token::LBR);
        this->stmt(input);
        if (input.check(Token::RBR)) {
            this->process(input, Token::RBR);
            this->primary_tail(input);
        } else {
            throw ParseException();
        }
    }
}

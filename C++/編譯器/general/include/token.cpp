#include "token.hpp"

Token::Token(Values value) : value(value) {}

std::regex Token::to_regex() const {
    auto iter = TokenSetting::regexs.find(this->value);
    return iter == TokenSetting::regexs.end() ? std::regex() : iter->second;
}

std::string Token::to_string() const {
    auto iter = TokenSetting::strings.find(this->value);
    return iter == TokenSetting::strings.end() ? "" : iter->second;
}
#include "input_stream.hpp"

InputStream::InputStream(const std::string& text) : std::string(text) {}

InputStream::InputStream() = default;

std::string InputStream::peep(const Token& token) const {
    std::smatch match;
    regex_search(*this, match, token.to_regex());
    return match.str();
}

bool InputStream::check(const Token& token) const {
    return !this->peep(token).empty();
}

void InputStream::pop(const Token& token) {
    *this = regex_replace(*this, token.to_regex(), "");
}

bool InputStream::empty() const { return std::string::empty(); }

const std::string InputStream::to_string() const { return *this; }
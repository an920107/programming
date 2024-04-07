#ifndef _TOKEN_
#define _TOKEN_

#include <map>
#include <regex>
#include <string>

class Token {
   public:
    enum Values { ID, STRLIT, LBR, RBR, DOT, SPACE };

   private:
    Values value;

   public:
    Token(Values value);
    Token();

    std::regex to_regex() const;
    std::string to_string() const;
};

namespace TokenSetting {
static const std::map<Token::Values, std::regex> regexs = {
    {Token::ID, std::regex("^ *[A-Za-z_][A-Za-z0-9_]*")},
    {Token::STRLIT, std::regex("^ *\"[^\"]*\"")},
    {Token::LBR, std::regex("^ *\\(")},
    {Token::RBR, std::regex("^ *\\)")},
    {Token::DOT, std::regex("^ *\\.")},
    {Token::SPACE, std::regex("^ *")},
};
static const std::map<Token::Values, std::string> strings = {
    {Token::ID, "ID"},   {Token::Values::STRLIT, "STRLIT"},
    {Token::LBR, "LBR"}, {Token::Values::RBR, "RBR"},
    {Token::DOT, "DOT"}, {Token::SPACE, "SPACE"},
};
}  // namespace TokenSetting

#endif
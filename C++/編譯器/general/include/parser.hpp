#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include <string>
#include <vector>

#include "input_stream.hpp"

class Parser {
   private:
    std::string text;
    std::vector<std::string> result;

    void process(InputStream&, const Token&);

    void program(InputStream&);
    void stmts(InputStream&);
    void stmt(InputStream&);
    void primary(InputStream&);
    void primary_tail(InputStream&);

   public:
    Parser(const std::string&);
    Parser();

    std::vector<std::string> parse();
};

#endif
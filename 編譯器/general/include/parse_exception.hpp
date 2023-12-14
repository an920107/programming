#ifndef _PARSE_EXCEPTION_HPP_
#define _PARSE_EXCEPTION_HPP_

#include <iostream>

class ParseException : public std::exception {
   public:
    ParseException();
    char* what();
};

#endif
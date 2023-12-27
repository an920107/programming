#ifndef _COMPILE_ERROR_HPP_
#define _COMPILE_ERROR_HPP_

#include <stdexcept>

class SyntaxError : public std::runtime_error {
   public:
    SyntaxError();
};

#endif
#ifndef _INPUR_STREAM_HPP_
#define _INPUR_STREAM_HPP_

#include <string>

#include "token.hpp"

class InputStream : private std::string {
   public:
    InputStream(const std::string&);
    InputStream();

    std::string peep(const Token&) const;
    bool check(const Token&) const;
    void pop(const Token&);
    bool empty() const;
    const std::string to_string() const;
};

#endif
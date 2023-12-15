#include "util.hpp"

std::vector<std::string> split(std::string str, std::string sep) {
    std::vector<std::string> result;
    while (true) {
        auto loc = str.find(sep);
        if (loc == std::string::npos) break;
        result.push_back(str.substr(0, loc));
        str = str.substr(loc + sep.length());
    }
    result.push_back(str);
    return result;
}

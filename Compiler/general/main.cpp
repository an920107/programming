#include <iostream>

#include "include/parse_exception.hpp"
#include "include/parser.hpp"

using namespace std;

int main() {
    std::string line, text;
    while (std::getline(std::cin, line)) text += line;
    try {
        for (auto parsed : Parser(line).parse()) std::cout << parsed << "\n";
    } catch (const ParseException& e) {
        std::cout << "invalid input\n";
    }
    return 0;
}

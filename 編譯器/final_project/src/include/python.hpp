#ifndef _PYTHON_HPP_
#define _PYTHON_HPP_

#include <fstream>
#include <iostream>
#include <queue>
#include <string>

class Python {
   private:
    std::queue<std::string> cmds;

   public:
    std::string filename;

   public:
    Python();
    void commit(std::string);
    std::string exec();
};

#endif
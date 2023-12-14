#ifndef _PYTHON_HPP_
#define _PYTHON_HPP_

#include <iostream>
#include <fstream>
#include <queue>
#include <string>

class Python {
   private:
    std::queue<std::string> cmds;

   public:
    Python();

    void commit(std::string);

    std::string exec();
};

#endif
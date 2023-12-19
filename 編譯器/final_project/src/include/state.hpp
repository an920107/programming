#ifndef _STATE_
#define _STATE_

#include <vector>

#include "object.hpp"

class State : public std::vector<ASTNode*> {
   public:
    State(ASTNode* root);
    ASTNode* append(ASTNode* node);
    Object* find(std::string name);
    void declare(Object* obj);
    void reset();

    static Function* find_nearest_function(ASTNode* node);
};

#endif
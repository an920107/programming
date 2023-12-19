#ifndef _STATE_
#define _STATE_

#include <vector>

#include "object.hpp"

// 紀錄當前 ast node
class State : public std::vector<ASTNode*> {
   public:
    State(ASTNode* root);
    ASTNode* append(ASTNode* node); // push_back 並 append 到 ast node 後
    Object* find(std::string name); // 往 parent 尋找最近的 define
    void declare(Object* obj); // 往 parent 尋找最近的 Function 並宣告變數
    void reset();

    static Function* find_nearest_function(ASTNode* node);
};

#endif
#ifndef _TREE_NODE_HPP_
#define _TREE_NODE_HPP_

#include "token.hpp"

class TreeNode {
   private:
    TreeNode *left = nullptr, *right = nullptr;

   public:
    enum LR : bool { LEFT, RIGHT };

    Token token;
    std::string code;

    TreeNode();
    TreeNode(const Token &, const std::string &);

    TreeNode *get(LR) const;
    void set(LR, TreeNode *);
    void remove(LR);
};

#endif
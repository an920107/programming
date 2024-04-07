#ifndef _TREE_HPP_
#define _TREE_HPP_

#include <vector>

#include "tree_node.hpp"

class Tree {
   private:
    TreeNode root;

   public:
    Tree();
    std::vector<const TreeNode> dfs() const;
};

#endif
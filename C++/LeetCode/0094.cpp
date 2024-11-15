#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* _left, TreeNode* _right) :
        val(x), left(_left), right(_right) {}
};


class Solution {
private:
    void __inorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;

        __inorder(root->left, result);
        result.emplace_back(root->val);
        __inorder(root->right, result);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        __inorder(root, result);
        return result;
    }
};

int main() {
    
    return 0;
}
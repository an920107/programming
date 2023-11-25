#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Sequence : public vector<T> {
   public:
    friend istream &operator>>(istream &is, Sequence<T> &seq) {
        seq.emplace_back();
        is >> seq.back();
        return is;
    }

    friend ostream &operator<<(ostream &os, const Sequence<T> &seq) {
        for (int i = 0; i < seq.size(); i++) {
            cout << seq[i] << (i == seq.size() - 1 ? "" : " ");
        }
        return os;
    }
};

struct Node {
    int data = 0;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
};

class BinaryTree {
   public:
    Node *root = nullptr;

    BinaryTree() {}

    BinaryTree(vector<int> &nums) {
        function<void(Node *&, int)> insert = [&](Node *&node, int i) {
            if (i >= nums.size() || nums[i] == 0) return;
            node = new Node;
            node->data = nums[i];
            insert(node->left, i * 2 + 1);
            insert(node->right, i * 2 + 2);
        };
        insert(root, 0);
    }

    Sequence<int> preorder() {
        Sequence<int> result;
        function<void(Node *)> dfs = [&](Node *node) {
            if (node == nullptr) return;
            result.emplace_back(node->data);
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        return result;
    }

    Sequence<int> inorder() {
        Sequence<int> result;
        function<void(Node *)> dfs = [&](Node *node) {
            if (node == nullptr) return;
            dfs(node->left);
            result.emplace_back(node->data);
            dfs(node->right);
        };
        dfs(root);
        return result;
    }

    Sequence<int> postorder() {
        Sequence<int> result;
        function<void(Node *)> dfs = [&](Node *node) {
            if (node == nullptr) return;
            dfs(node->left);
            dfs(node->right);
            result.emplace_back(node->data);
        };
        dfs(root);
        return result;
    }
};

int main() {
    Sequence<int> nums;
    int t;
    cin >> t;
    while (t--) cin >> nums;
    BinaryTree bt(nums);
    cout << bt.preorder() << "\n"
         << bt.inorder() << "\n"
         << bt.postorder() << "\n";
    return 0;
}
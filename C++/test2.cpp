#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Sequence : public vector<T> {
   public:
    friend istream &operator>>(istream &is, Sequence<T> &seq) {
        seq.emplace_back();
        if (!(is >> seq.back()))
            seq.pop_back();
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

    void swap_children() {
        swap(this->left, this->right);
        if (this->left != nullptr)
            this->left->swap_children();
        if (this->right != nullptr)
            this->right->swap_children();
    }
};

class BinaryTree {
   public:
    Node *root = nullptr;

    BinaryTree() {}

    BinaryTree(vector<int> &nums) {
        function<void(Node *&, int)> insert = [&](Node *&node, int i) {
            if (i >= nums.size()) return;
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

    Sequence<int> layerorder() {
        Sequence<int> result;
        queue<Node*> bfs_queue;
        unordered_map<Node*, bool> visited;
        bfs_queue.emplace(root);
        while (!bfs_queue.empty()) {
            Node* current = bfs_queue.front();
            bfs_queue.pop();
            if (visited[current]) continue;
            visited[current] = true;
            if (current == nullptr) continue;
            result.emplace_back(current->data);
            bfs_queue.emplace(current->left);
            bfs_queue.emplace(current->right);
        }
        return result;
    }

    Node* find(int val) {
        Node* result = nullptr;
        function<void(Node*)> dfs = [&](Node* node) {
            if (node == nullptr) return;
            if (node->data == val) {
                result = node;
                return;
            }
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        return result;
    }
};

int main() {
    Sequence<int> nums;
    string line;
    stringstream ss;
    getline(cin, line);
    ss << line;
    while (ss >> nums);
    BinaryTree bt(nums);
    int num;
    while (cin >> num)
        bt.find(num)->swap_children();
    cout << bt.layerorder() << " \n";
    return 0;
}
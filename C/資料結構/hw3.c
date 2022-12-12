#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TREE_INIT\
    {NULL, tree_clear, tree_insert, tree_preorder, tree_inorder, tree_postorder}

typedef struct _Node {
    int data;
    struct _Node *left;
    struct _Node *right;
} Node;

typedef struct _BinaryTree {
    Node *root;
    void (*clear)(struct _BinaryTree*);
    void (*insert)(struct _BinaryTree*, int);
    void (*preorder)(struct _BinaryTree*);
    void (*inorder)(struct _BinaryTree*);
    void (*postorder)(struct _BinaryTree*);
} BinaryTree;

void node_insert(Node **root, int val) {
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->data = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }

    if (val < (*root)->data) {
        node_insert(&(*root)->left, val);
    }
    else {
        node_insert(&(*root)->right, val);
    }
}

void node_preorder(Node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    node_preorder(root->left);
    node_preorder(root->right);
}

void node_inorder(Node *root) {
    if (root == NULL)
        return;
    node_inorder(root->left);
    printf("%d ", root->data);
    node_inorder(root->right);
}

void node_postorder(Node *root) {
    if (root == NULL)
        return;
    node_postorder(root->left);
    node_postorder(root->right);
    printf("%d ", root->data);
}

//

void tree_insert(BinaryTree *self, int val) {
    node_insert(&self->root, val);
}

void tree_preorder(BinaryTree *self) {
    node_preorder(self->root);
}

void tree_inorder(BinaryTree *self) {
    node_inorder(self->root);
}

void tree_postorder(BinaryTree *self) {
    node_postorder(self->root);
}

void tree_clear(BinaryTree *self) {
    BinaryTree tree = TREE_INIT;
    *self = tree;
}

//

int main() {
    int n, i, num;
    BinaryTree tree = TREE_INIT;
    while (scanf("%d", &n) != EOF && n != -1) {
        for (i = 0; i < n; i ++) {
            scanf("%d", &num);
            tree.insert(&tree, num);
        }
        printf("Preorder: ");
        tree.preorder(&tree);
        printf("\nInorder: ");
        tree.inorder(&tree);
        printf("\nPostorder: ");
        tree.postorder(&tree);
        printf("\n\n");
        tree.clear(&tree);
    }
    return 0;
}
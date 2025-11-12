// 7. Write a program to count leaf nodes and non-leaf nodes

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = v;
    n->left = n->right = NULL;
    return n;
}

int countLeaf(struct Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

int countNonLeaf(struct Node* root) {
    if (!root || (!root->left && !root->right)) return 0;
    return 1 + countNonLeaf(root->left) + countNonLeaf(root->right);
}

int main() {
    struct Node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    printf("Leaf nodes = %d\n", countLeaf(root));
    printf("Non-leaf nodes = %d\n", countNonLeaf(root));
}

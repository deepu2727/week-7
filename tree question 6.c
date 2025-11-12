// 6. Write a program to find the height of a binary tree

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

int height(struct Node* root) {
    if (!root) return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}

int main() {
    struct Node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    printf("Height of tree: %d", height(root));
}

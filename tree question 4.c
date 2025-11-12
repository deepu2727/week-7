// 4. Find Minimum and Maximum in a BST

#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

struct Node* newNode(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = v; n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int v) {
    if (!root) return newNode(v);
    if (v < root->data) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
    return root;
}

int findMin(struct Node* root) {
    while (root->left) root = root->left;
    return root->data;
}

int findMax(struct Node* root) {
    while (root->right) root = root->right;
    return root->data;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50); insert(root, 30); insert(root, 70);
    printf("Min: %d\n", findMin(root));
    printf("Max: %d\n", findMax(root));
}

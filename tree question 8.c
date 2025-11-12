// 8. Write a program to mirror a binary tree

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

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void mirror(struct Node* root) {
    if (!root) return;
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

int main() {
    struct Node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    printf("Inorder before mirroring: ");
    inorder(root);

    mirror(root);

    printf("\nInorder after mirroring: ");
    inorder(root);
}

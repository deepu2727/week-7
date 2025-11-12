// Delete a Node from BST

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = v;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int v) {
    if (!root) return newNode(v);
    if (v < root->data) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

struct Node* delete(struct Node* root, int key) {
    if (!root) return NULL;
    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else {
        if (!root->left) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder before deletion: ");
    inorder(root);

    root = delete(root, 70);

    printf("\nInorder after deleting 70: ");
    inorder(root);
}

#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
struct Node* insertNode(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

// Function to find the minimum value node in a BST
struct Node* findMinNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted is found

        // Case 1: Node is a leaf node or has a single child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node has two children
        struct Node* minNode = findMinNode(root->right);
        root->key = minNode->key;
        root->right = deleteNode(root->right, minNode->key);
    }

    return root;
}

// Function to print the inorder traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert nodes in the BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Print the inorder traversal of the BST
    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Delete a node from the BST
    root = deleteNode(root, 20);
    printf("After deleting 20, the inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("After deleting 30, the inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("After deleting 50, the inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
    
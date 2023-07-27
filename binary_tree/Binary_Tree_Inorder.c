/* You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.*/
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node with the given value
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into a Binary Search Tree (BST)
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        root = createNode(val);
        return root;
    }

    if (root->val > val) {
        root->left = insertIntoBST(root->left, val);
    } else if (root->val < val) {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Function to perform in-order traversal of the BST (for testing purposes)
void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    printf("%d ", root->val);
    inOrderTraversal(root->right);
}

int main() {
    // Create an empty BST
    struct TreeNode* root = NULL;

    // Insert elements into the BST
    root = insertIntoBST(root, 5);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 7);
    root = insertIntoBST(root, 2);
    root = insertIntoBST(root, 4);

    // Perform in-order traversal to verify the BST structure
    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);

    return 0;
}


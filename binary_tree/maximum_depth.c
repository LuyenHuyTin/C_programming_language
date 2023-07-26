/* Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/
#include <stdio.h>
#include <stdlib.h>

/* Definition for a binary tree node */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

/* Helper function to create a new binary tree node */
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Driver program to test the code */
int main() {
    struct TreeNode *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Maximum depth of the binary tree is: %d\n", maxDepth(root));

    return 0;
}

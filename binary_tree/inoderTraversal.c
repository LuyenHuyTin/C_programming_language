/* Given the root of a binary tree, return the inorder traversal of its nodes' values. */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int idx = 0;

void checkindex(struct TreeNode *root, int *val){
    if(root == NULL){
        return;
    }
    checkindex(root->left, val);
    val[idx] = root->val;
    idx++;
    checkindex(root->right, val);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    idx = 0;
    int *val = (int*)malloc(100*sizeof(int)); // assuming the tree has at most 100 nodes
    checkindex(root, val);
    *returnSize = idx;
    return val;
}

int main() {
    // create a binary tree
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->right->left = malloc(sizeof(struct TreeNode));
    root->right->left->val = 4;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = malloc(sizeof(struct TreeNode));
    root->right->right->val = 5;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    // call inorderTraversal to print the inorder traversal of the tree
    int size;
    int* vals = inorderTraversal(root, &size);
    printf("Inorder Traversal: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", vals[i]);
    }
    printf("\n");

    // free the memory allocated for the tree and the array
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);
    free(vals);

    return 0;
}

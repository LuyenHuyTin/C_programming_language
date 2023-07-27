/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int idx=0;
void checkindex(struct TreeNode *root, int *val){
    if(root==NULL){
        return;
    }
    val[idx] = root->val;
    idx++;
    checkindex(root->left, val);
    checkindex(root->right, val);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
        if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    idx=0;
    int *val = (int*)malloc(100*sizeof(int));
    checkindex(root, val);
    *returnSize = idx;
    return val;
}

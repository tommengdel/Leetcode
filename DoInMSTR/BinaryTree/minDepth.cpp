/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == 0) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(left == 0 || right == 0) return left + right + 1;
        else return min(left, right) + 1;
    }
};
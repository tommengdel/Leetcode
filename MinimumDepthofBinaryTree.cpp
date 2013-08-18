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
    int min(int a, int b) { return a < b ? a : b; }
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == 0) return 0;
        int lh = minDepth(root->left);
        int rh = minDepth(root->right);
        if(lh == 0 || rh == 0) return lh + rh + 1;
        else return min(lh, rh) + 1;
    }
};


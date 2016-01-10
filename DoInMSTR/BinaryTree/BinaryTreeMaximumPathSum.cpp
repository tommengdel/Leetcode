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
    int maxVal;
public:
    int maxPathSum(TreeNode *root) {
        if(root == 0) return 0;
        maxVal = root->val;
        maxPathSumRecur(root);
        return maxVal;
    }
    
    int maxPathSumRecur(TreeNode *root) {
       if(root == 0) return 0;
       int leftMax = (root->left == 0) ? 0 : maxPathSumRecur(root->left);
       int rightMax = (root->right == 0) ? 0 : maxPathSumRecur(root->right);
       
       int curPathVal = leftMax + rightMax + root->val;
       maxVal = max(curPathVal, maxVal);
       int maxPath = max(leftMax, rightMax) + root->val;
       return max(0, maxPath);
     }
};
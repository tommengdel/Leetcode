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
    bool isLeaf(TreeNode *root) {
        return root->right == 0 && root->left == 0;
    }
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == 0) return false; //Forget this statement
        
        if(isLeaf(root)) return root->val == sum;
        return (root->left != 0 && hasPathSum(root->left, sum - root->val))
            || (root->right != 0 && hasPathSum(root->right, sum - root->val));
        ;
    }
};


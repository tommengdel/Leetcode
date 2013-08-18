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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *tree1, TreeNode *tree2) {
        if((tree1 == 0 && tree2 != 0)|| (tree1 != 0 && tree2 == 0)) return false;
        if(tree1 == 0 && tree2 == 0) return true;
        else return (tree1->val == tree2->val) && isSymmetric(tree1->left, tree2->right) 
                && isSymmetric(tree1->right, tree2->left);
    }
};


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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flatten1(root);
    }
    
    TreeNode *flatten1(TreeNode *root) {
        if(root == 0) return 0;
        TreeNode *right = root->right;
        
        root->right = flatten1(root->left);
        root->left = 0;
        
        TreeNode *lastNode = root;
        while(lastNode->right != 0) lastNode = lastNode->right;
        lastNode->right = flatten1(right);
        return root;
    }
};
//Use Recursion

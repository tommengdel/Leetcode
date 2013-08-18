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
    int max(int a, int b) { return a > b ? a : b; }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return checkHeight(root) != -1;
    }
    
    int checkHeight(TreeNode *root) {
        if(root == 0) return 0;
        int lh = checkHeight(root->left);
        int rh = checkHeight(root->right);
        
        if(lh == -1||rh == -1 || abs(rh - lh) > 1) return -1;
        
        return max(lh, rh) + 1;
    }
};
//忘记写lh == -1和rh == -1的条件，险些出错

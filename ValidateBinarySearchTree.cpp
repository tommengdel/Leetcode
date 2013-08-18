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
    int TreeMinimum(TreeNode *root) {
        if(root == 0) return 0;
        while(root->left != 0) root = root->left;
        return root->val;
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int prev_value = TreeMinimum(root) - 1;
        return  checkInorder(root, prev_value);
    }
    
    bool checkInorder(TreeNode *root, int &prev_value) {
        if(root != 0) {
            if(!checkInorder(root->left, prev_value)) return false;
            if(root->val <= prev_value) return false;
            prev_value = root->val;
            if(!checkInorder(root->right, prev_value)) return false;
        }
        return true;
    }
};
//没有仔细看清楚题目，27行写了小于号，而应该是小于等于号

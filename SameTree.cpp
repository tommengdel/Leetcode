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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //if((p == 0 && q != 0) ||(p != 0 && q == 0)) return false;
        if(p == 0 && q == 0) return true;
            
        if(p != 0 && q!= 0 && p->val == q->val) 
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
    }
};


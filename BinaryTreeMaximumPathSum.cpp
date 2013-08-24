/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

//All is negative ?? how to do? 

//Contain Zero? 
class Solution {
    int max(const int& a, const int& b) { return a > b ? a : b; }
    int maxvalue;
public:
    int maxPathSum(TreeNode *root) {
        
	maxvalue = root->val; //This is also important
        maxRootPathSum(root);
        return maxvalue;
    }
    
    int maxRootPathSum(TreeNode *root) {
        if(root == 0) return 0;
        int leftMax = maxRootPathSum(root->left);
        int rightMax = maxRootPathSum(root->right);
        
        rightMax = rightMax > 0 ? rightMax : 0;
        leftMax = leftMax > 0 ? leftMax : 0;
        int cur = rightMax + leftMax + root->val;
        maxvalue = maxvalue > cur ? maxvalue : cur;
	// I make a guarante that every path must contain at least a Node
        return root->val + max(rightMax, leftMax);
    }
};


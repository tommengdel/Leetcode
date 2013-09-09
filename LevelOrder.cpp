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
    vector<vector<int> > ret;
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        levelOrder(root, 0);
        return ret;
    }
    
    void levelOrder(TreeNode *root, int level) {
        if(root == 0) return ;
        if(ret.size() <= level) ret.push_back(vector<int>());
        ret[level].push_back(root->val);
        levelOrder(root->left, level + 1);
        levelOrder(root->right, level + 1);
    }
};
//A beautiful algorithm for level order

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
    int allSum;
    bool isLeaf(TreeNode *root) {
        return root->left == 0 && root->right == 0;
    }
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == 0) return 0;
        allSum = 0;
        sumNumbers(root, 0);  
        return allSum;
    }
    void sumNumbers(TreeNode *root, int prev) {
        prev = prev *10 + root->val;
        if(isLeaf(root)) allSum += prev;
        else {
            if(root->left != 0) sumNumbers(root->left, prev);
            if(root->right != 0) sumNumbers(root->right, prev);
        }
    }
};


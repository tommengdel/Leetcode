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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sortedArrayToBST(num.begin(), num.end());
    }
    
    TreeNode *sortedArrayToBST(vector<int>::iterator start, vector<int>::iterator end) {
        int len = end - start;
        if(len == 0) return 0;
        if(len == 1) return new TreeNode(*start); //Optional statement
        vector<int>::iterator mid = start + len / 2;
        TreeNode *root = new TreeNode(*mid);
        root->left = sortedArrayToBST(start, mid);
        root->right = sortedArrayToBST(mid + 1, end);
        return root;
    }
};


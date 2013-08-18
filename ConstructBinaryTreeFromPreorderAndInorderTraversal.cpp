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
    typedef vector<int>::iterator CI;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());   
    }
    TreeNode *buildTree(CI pre_s, CI pre_e, CI in_s, CI in_e) {
        int len = pre_e - pre_s;
        if(len == 0) return 0;
        if(len == 1) return new TreeNode(*pre_s);
        
        CI mid = find(in_s, in_e, *pre_s);
        
        int leftlen = mid - in_s;
        int rightlen = in_e - mid - 1; 
        
        TreeNode *leftChild = buildTree(pre_s + 1, pre_s + leftlen + 1, in_s, mid);
        TreeNode *rightChild = buildTree(pre_s + leftlen + 1, pre_e, mid + 1, in_e);
        
        TreeNode *root = new TreeNode(*pre_s);
        root->left = leftChild;
        root->right = rightChild;
        return root;
    }
};


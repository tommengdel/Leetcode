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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    
    TreeNode *buildTree(vector<int>::iterator indBegin,vector<int>::iterator indEnd,vector<int>::iterator postBegin,vector<int>::iterator postEnd) {
        if(postEnd <= postBegin) return NULL;
        int rootVal = *(postEnd - 1);
        TreeNode *root = new TreeNode(rootVal);
        
        vector<int>::iterator rootIter = find(indBegin, indEnd, rootVal);
        int leftSize = rootIter - indBegin;
        int rightSize = indEnd - rootIter - 1;
        
        TreeNode *left = buildTree(indBegin, rootIter, postBegin, postBegin + leftSize);
        TreeNode *right = buildTree(rootIter + 1, indEnd, postBegin + leftSize, postEnd - 1);
        
        root->left = left;
        root->right = right;
        return root;
    }
};
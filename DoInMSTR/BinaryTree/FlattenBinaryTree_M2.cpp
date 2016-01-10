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
        stack<TreeNode *> st;
        //Preprocess
        TreeNode fakeHead(0);
        TreeNode *curListPointer = &fakeHead;
        
        if(root != 0) st.push(root);
        TreeNode *cur;
        while(!st.empty()) {
             cur = st.top(); st.pop();
             curListPointer->right = cur;
             while(cur != 0) {
                 curListPointer = cur;
                 if(cur->right != 0) st.push(cur->right);
                 cur->right = cur->left;
                 cur->left = 0; 
                 cur = cur->right;
             }
             
        }
    }
    
};
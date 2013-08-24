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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        stack<TreeNode *> st;
        if(root != 0) st.push(root);
        while(!st.empty()) {
            TreeNode *p = st.top();
            while(p->left != 0) {
                p = p->left;
                st.push(p);
            }
            
            ret.push_back(p->val); st.pop(); //All the node visited must be Pop()
            while(p->right == 0 && !st.empty()) {
                p = st.top();
                st.pop(); ret.push_back(p->val);
            }
            
            if(p->right != 0) st.push(p->right); 
        }
        
        return ret;
    }
};


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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        stack<TreeNode*> st;
        vector<int> ret;
        st.push(root);
        while(!st.empty()) {
            TreeNode* r  = st.top(); st.pop();
            while(r != 0) {
                ret.push_back(r->val);
                st.push(r->right);
                r = r->left;
            }
        }
        return ret;
    }
};


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
    vector<int> postorderTraversal(TreeNode *root) {
         stack<TreeNode *> st;
         vector<int> result;
         //Preprocess
         TreeNode *cur = root;
         while(cur != 0) {
             st.push(cur); 
             cur = cur->left;
         }
         
         while(!st.empty()) {
             cur = st.top(); st.pop();
             if(cur->right != 0) {
                 //we must process right sub tree first
                 st.push(cur);
                 TreeNode *temp = cur->right;
                 while(temp != 0) {
                     st.push(temp); 
                     temp = temp->left;
                 }
             }
             else {
                 //cur->right == 0 
                 //CAN CHANGE TO DO WHILE
                 result.push_back(cur->val);
                 while(!st.empty() && (st.top()->right == cur)) {
                     cur = st.top(); st.pop();
                     result.push_back(cur->val);
                 }
             }
         }
         return result;
    }
};
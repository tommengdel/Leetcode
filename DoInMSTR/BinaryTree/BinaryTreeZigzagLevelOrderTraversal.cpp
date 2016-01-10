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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode *> nodeQueue;
        if(root == 0) return result;
        nodeQueue.push(NULL);
        nodeQueue.push(root);
        
        while(!nodeQueue.empty()) {
            TreeNode *cur = nodeQueue.front();
            nodeQueue.pop();
            if(cur == NULL){
                if(nodeQueue.empty()) break;
                else {
                   result.push_back(vector<int>());
                   nodeQueue.push(NULL);
                }
            } else {
                result.back().push_back(cur->val);
                if(cur->left != 0) nodeQueue.push(cur->left);
                if(cur->right != 0) nodeQueue.push(cur->right);
            }
        }
        
        for(int i = 1; i < result.size(); i += 2) {
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
};
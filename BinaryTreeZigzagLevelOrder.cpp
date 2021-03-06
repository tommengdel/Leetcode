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
    vector<vector<int> > levelLists;
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        levelLists.clear();
        levelOrder(root);
        for(int i = 1; i < levelLists.size(); i += 2)
            reverse(levelLists[i].begin(), levelLists[i].end());
        return levelLists;
        
    }
     void levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
     //   vector<vector<int>> levelLists;
        if(root == 0) return;//This statement must be before the next statement, or it will raise an error
        levelLists.push_back(vector<int>());
        
        TreeNode *parent, sentinal(0), *sentinalptr = &sentinal;
        queue<TreeNode *>q;
      
        q.push(root);
        q.push(sentinalptr);
        
        while(!q.empty()) {
            parent = q.front(); q.pop();
            if(parent == sentinalptr) {
                if(q.empty()) break;
                else {
                    parent = q.front(); q.pop();
                    q.push(sentinalptr);
                    levelLists.push_back(vector<int>());
                }
            }
            levelLists.back().push_back(parent->val);
            if(parent->left != 0) q.push(parent->left);
            if(parent->right != 0) q.push(parent->right);
        }
        
        //return levelLists;
    }
};
//不知道是不是有什么更好的办法可以做这件事情

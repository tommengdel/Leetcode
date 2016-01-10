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
    bool isSymmetric(TreeNode *root) {
        if(root == 0 || (root->left == 0 && root->right == 0)) return true;
        if(root->left != 0 && root->right != 0) {
            queue<TreeNode*> qleft;
            queue<TreeNode*> qright; 
            qleft.push(root->left);
            qright.push(root->right);
            
            while(!qleft.empty() && !qright.empty()) {
                TreeNode *curLeft = qleft.front();
                TreeNode *curRight = qright.front();
                qleft.pop(); qright.pop();
                if((curLeft != 0 && curRight != 0 && (curLeft->val != curRight->val))
                    || (curLeft == 0 && curRight != 0)
                    || (curRight == 0 && curLeft != 0)) {
                        return false;
                }
                else {
                    if(curLeft != 0) {
                        qleft.push(curLeft->left);
                        qleft.push(curLeft->right);
                    }
                    if(curRight != 0) {
                        qright.push(curRight->right);
                        qright.push(curRight->left);
                    }
                }
                
            }
            return qleft.empty() && qright.empty(); // Make a mistake here.
        }
        return false;
    }
};

//Need to add another test case on Leetcode {1,2,2,3,4} , or Error Code can also pass.
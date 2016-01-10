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
    struct List {
        TreeNode *head, *end;
        List(): head(0), end(0) {}
        List(TreeNode* head, TreeNode* end):head(head), end(end) {}
    };
public:
    void flatten(TreeNode *root) {
        flattenTree(root);
    }
    List flattenTree(TreeNode *root) {
        if(root == 0) return List();
        List leftSub = flattenTree(root->left);
        List rightSub = flattenTree(root->right);
        List ret;
        ret.head = ret.end = root;
        
        root->left = root->right = 0;
        if(leftSub.head == 0) {
            root->right = rightSub.head;
            ret.end = rightSub.end == 0 ? root : rightSub.end;
        } else {
            root->right = leftSub.head;
            leftSub.end->right = rightSub.head;
            ret.end = rightSub.end == 0 ? leftSub.end : rightSub.end;
        }
        
        return ret;
    }
};

//Something we can improve: actually we don't need to maintain the list, just need to update the right child pointer
//It is kind of like inorder traversal

//This code also can improve its code quality
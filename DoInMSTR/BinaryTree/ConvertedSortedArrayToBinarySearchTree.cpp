class Solution {
    vector<int>::iterator curItem;
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int treeNum = num.size();
        curItem = num.begin();
        return sortedArrayToBST(treeNum);
    }
    
    TreeNode* sortedArrayToBST(int treeNum) {
        if(treeNum == 0) return 0;
        if(treeNum == 1) return new TreeNode(*curItem++);
        else {
            TreeNode *left = sortedArrayToBST((treeNum - 1) / 2);
            TreeNode *root = new TreeNode(*curItem++);
            TreeNode *right = sortedArrayToBST(treeNum - 1 -  (treeNum - 1) / 2);
            root->left = left;
            root->right = right;
            return root;
        }
    }
    //I can improve it use iterator, make it a generalized algorithm for list and array.
};
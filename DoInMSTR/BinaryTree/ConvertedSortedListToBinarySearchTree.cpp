/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode *curItem;
public:
    TreeNode *sortedListToBST(ListNode *head) {
        curItem = head;
        int listsize = getListSize(head);
        return sortedListToBST(listsize);
    }
    
    int getListSize(ListNode *head) {
        int count = 0;
        while(head != 0) {
            ++count;
            head = head->next;
        }
        return count;
    }
    
    TreeNode *sortedListToBST(int n) {
        TreeNode *root = 0;
        if(n == 1) {
            root = new TreeNode(curItem->val);
            curItem = curItem->next;
        } else if(n > 1) {
            TreeNode *left = sortedListToBST(( n - 1) / 2);
            root = new TreeNode(curItem->val); 
            curItem = curItem->next;
            TreeNode *right = sortedListToBST(n - 1 - (n - 1) / 2);
            root->left = left;
            root->right = right;
        }
        return root;
    }
};
//I can still use another method, build the tree first, then I can use inorder traversal.
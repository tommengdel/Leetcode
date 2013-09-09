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
    ListNode *data;
    int getData() {
        if(data == 0) return -1;
	int ret = data->val;
	data = data->next;
	return ret;

//     ListNode *temp = data;
//     data = data->next;
//     return temp->val;
//
//
	/**
	 * My former Mistake
	 * return data->val;
	 * data = data->next;
	 *
	 * Every statement after the return will not be executed
	 *
	 */
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
        //Count the number of nodes;
        
        int count = 0; 
        for(ListNode *iter = head; iter != 0; iter = iter->next) ++count;
        data = head;
        return CreateBinarySearchTree(count);       
    }
    
    TreeNode *CreateBinarySearchTree(int size) {
        if(size == 0) return 0;
        if(size == 1) {
            return new TreeNode(getData());
        }
        else {
            TreeNode *left = CreateBinarySearchTree((size - 1) / 2);
            TreeNode *root = new TreeNode(getData());
            TreeNode *right = CreateBinarySearchTree(size - 1 - (size - 1) / 2);
            root->left = left;
            root->right = right;
            return root;
        }
        
    }
    
};


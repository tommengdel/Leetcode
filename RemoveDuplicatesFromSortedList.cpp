/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *iter = head;
        while(iter != 0 && iter->next != 0) {
            if(iter->val == iter->next->val) {
                iter->next = iter->next->next;
            }
            else {
                iter = iter->next;
            }
        }
        return head;
    }
};


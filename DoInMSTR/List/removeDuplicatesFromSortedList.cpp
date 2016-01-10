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
        ListNode *cur, *next;
        cur = head;
        while(cur != 0) {
           next = cur->next;
           while(next != 0 && next->val == cur->val) {
               cur->next = next->next;
               delete next;
               next = cur->next;
           }
           cur = cur->next;
        }
        return head;
    }
};
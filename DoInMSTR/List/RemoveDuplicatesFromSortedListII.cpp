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
        ListNode temp(0);
        ListNode *fakeHead = &temp;
        fakeHead->next = head;
        
        ListNode *cur = head, *pre = fakeHead;
        
        while(cur != 0) {
            bool dup = false;
            ListNode *next = cur->next;
            while(next != 0 && next->val == cur->val) {
                dup = true;
                next = next->next;
            }
            
            if(dup) {
                pre->next = next;
                cur = pre->next; //Lack of this statements
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return fakeHead->next;
    }
};
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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *fast, *slow;
        fast = slow = head;
        if(head == 0) return head;
        do {
            fast = fast->next;
            fast = fast == 0? 0: fast->next;
            slow = slow->next;
        } while(fast != 0 && slow != fast);
        
        if(fast != 0){
            slow = head;
            while(slow != fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return fast;
    }
};


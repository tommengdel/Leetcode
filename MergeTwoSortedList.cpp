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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode virhead(0), *ins = &virhead;
        while(l1 != 0 && l2 != 0) {
            if(l1->val > l2->val) {
                ins->next = l2; 
                l2 = l2->next;
            }
            else {
                ins->next = l1;
                l1 = l1->next;
            }
            ins = ins->next;
        }
        
        ins->next = (l1 == 0) ? l2 : l1;
        return virhead.next;
    }
};


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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *iter1, *iter2;
        int c = 0, v;
        int radix  = 10;
        ListNode virhead(0), *ins = &virhead;
        iter1 = l1; iter2 = l2;
        while(iter1 != 0 && iter2 != 0) {
            v = iter1->val + iter2->val + c;
            c = v / radix;
            v = v % radix;
            l1->val = v;
            ins->next = l1;
            ins = ins->next;
            l1 = l1->next;
            
            iter1 = iter1->next;
            iter2 = iter2->next;
        }
        
        ListNode *rem = iter1 == 0 ? iter2 : iter1;
        ListNode *alloc = l2;
        
        while(rem != 0) {
            v = rem->val + c;
            c = v / radix;
            v = v % radix;
            
            if(alloc == 0) alloc = l1;
            alloc->val = v;
            ins->next = alloc;
            ins = ins->next;
            alloc = alloc->next;
            rem = rem->next;
        }
        
        if(c != 0) {
            ins->next = new ListNode(c);
            ins = ins->next;
        }
        ins->next = 0;
        return virhead.next;
    }
};

//还是太不细心了

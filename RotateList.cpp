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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *newhead, *newend, *iter;
        if(head == 0) return 0;
        int listsize, i;
        for(i = 1, iter = head; i <= k; ++i) {
            if(iter == 0) break;
            iter = iter->next;
        }
        
        if(iter == 0) {
            listsize = i - 1;
            k = k % listsize;
            for(i = 1, iter = head; i <= k; ++i) iter = iter->next;
        }
        if(k == 0) return head;
        
        newend = head;
        while(iter->next != 0) {
            iter = iter->next;
            newend = newend->next;
        }
        
        
        newhead = newend->next;
        newend->next = 0;
        iter->next = head;
        return newhead;
    }
};
//12ms 60ms

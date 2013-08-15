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
        ListNode virhead(0), *prev, *iter;
        prev = &virhead;
        iter = head;
        virhead.next = head;
        
        while(iter != 0) {
            bool dupl = false; //Does iter->val exist duplicates
            while(iter->next != 0 && iter->val == iter->next->val) {
                iter->next = iter->next->next;
                dupl = true;
            }
            
            if(dupl) { //Delete *iter
                prev->next = iter->next;
                iter = iter->next;
            }
            else {
                prev = iter;
                iter = iter->next;
            }
        }
        return virhead.next;
    }
};


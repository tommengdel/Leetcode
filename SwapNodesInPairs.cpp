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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode virhead(0), *prev = &virhead, *post1, *post2;
        virhead.next = head;
        post1 = head;
        post2 = post1 == 0 ? 0 : post1->next;
        
        while(post2 != 0) {
            post1->next = post2->next;
            post2->next = post1;
            prev->next = post2;
            
            prev = post1;
            post1 = post1->next;
            post2 = post1 == 0 ? 0 : post1->next;
        }
        return virhead.next;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(0){}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode virhead(0), *prev,*after, *new_nth, *new_mth, *iter1, *iter2, *iter3;
        iter1 = &virhead;

	virhead.next = head; // I forget this statement

        for(int i = 1; i <= m - 1; ++i) iter1 = iter1->next;
        prev = iter1;
        new_nth = iter1->next;
        
        iter1 = iter1->next;
        iter2 = iter1->next;
        iter3 = iter2 == 0 ? 0 :iter2->next;
        
        for(int i = 1; i <= n - m; ++i) {
            iter2->next = iter1;
            iter1 = iter2;
            iter2 = iter3;
            iter3 = iter3 == 0 ? 0 : iter3->next;
        }
        
        new_mth = iter1;
        after = iter2;
        prev->next = new_mth;
        new_nth->next = after;
        return virhead.next;
        
    }
};

int main() {
	ListNode head(0);
	Solution().reverseBetween(&head, 1, 1);
}



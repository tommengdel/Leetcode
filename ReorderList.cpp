/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode * ReverseLinkedList(ListNode *head) {
        ListNode *iter1, *iter2, *iter3;
        iter1 = head;
        iter2 = iter1 == 0 ? 0: iter1->next;
        iter3 = iter2 == 0 ? 0: iter2->next;
        if(iter1 != 0) iter1->next = 0;
        
        while(iter2 != 0) {
            iter2->next = iter1;
            iter1 = iter2;
            iter2 = iter3;
            iter3 = iter3 == 0 ? 0 : iter3->next;
        }
        return iter1;
    }
    
    int GetListLen(ListNode *head) {
        int count = 0;
        while(head != 0) {
            head = head->next;
            ++count;
        }
        return count;
    }
    
public:
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == 0) return;
        int len = GetListLen(head);
        ListNode *list1 = head, *list2 = head;
        
        for(int i = 0; i < (len - 1) / 2; ++i) list2 = list2->next;
        ListNode *tmp = ReverseLinkedList(list2->next);
        list2->next = 0;
        list2 = tmp;
        
        //Start to Merge List1 and List2
        while(list2 != 0) {
            tmp = list1->next;
            list1->next = list2;
            list1 = tmp;
            
            tmp = list2->next;
            list2->next = list1;
            list2 = tmp;
        }
    }
};


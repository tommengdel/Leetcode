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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(k < 2) return head;
        ListNode virhead(0), *ptr_virhead, *iter1, *iter2, *iter3; 
        virhead.next = head;
        ptr_virhead = &virhead;
        
        ListNode *start, *end; //[start, end];
        start = end = head;
        
        for(int i = 1; i <= k - 1 && end != 0; ++i) end = end->next;
        
        while(end != 0) {
            iter1 = ptr_virhead;
            iter2 = iter1->next;
            iter3 = iter2->next;
            
            while(iter1 != end) {
                iter2->next = iter1;
                iter1 = iter2;
                iter2 = iter3;
                iter3 = iter3 == 0 ? 0 : iter3->next;
            }
            
            ptr_virhead->next = end;
            start->next = iter2;
            ptr_virhead = start;
	    //Never forget to update every element
            start = end = iter2;
//            if(end != 0)  //This if-statement is important 
            for(int i = 1; i <= k - 1 && end != 0; ++i) end = end->next;
	    //for语句会测试初始化语句的条件的
        }
        return virhead.next;
    }
};


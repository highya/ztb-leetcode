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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n)
            return head;
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        m++;n++;
        ListNode* p1 = newhead;
        ListNode* p2 = newhead;
        for(int i=0;i<m-2;i++)
            p1 = p1->next;
        for(int i=0;i<n-1;i++)
            p2 = p2->next;
        ListNode* p1_former_record = p1;
        ListNode* p2_latter_record = p2->next;            
        p1 = p1->next;
        ListNode* p1_next = p1->next;
        ListNode* p1_next_next = p1_next->next;
        while(p1<p2){
            p1_next->next = p1;
            p1 = p1_next;
            p1_next = p1_next_next;
            p1_next_next = p1_next_next==NULL ? NULL :p1_next_next->next;
        }
        p1_former_record->next->next = p2_latter_record;
        p1_former_record->next = p2;
        return newhead->next;
    }
};

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL || head->next == NULL)
            return NULL;
        ListNode *p_former = head;
        ListNode *p_latter = head;
        
        for(int i=0;i<n;i++)
            p_latter = p_latter -> next;
        if(p_latter == NULL)
            return head->next;
        while(p_latter->next!=NULL)
        {
            p_latter = p_latter -> next;
            p_former = p_former -> next;
        }
        p_former -> next = (p_former -> next) -> next;
        return head;
    }
};

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
        if(head==NULL) return head;
        
        ListNode *result= new ListNode(0);
        ListNode *tail = result;
        tail->next=head;
        result->val=head->val;
        
        while(head->next!=NULL)
        {
            if(result->val != head->next->val)
            {
                result->val=head->next->val;
                
                if(tail->next != head)
                {
                    tail->next=head->next;
                }
                else
                {
                    tail->next=head;
                    tail=tail->next;
                }
            }
            head=head->next;
        }
        if(tail->next != head) tail->next=NULL;
        
        return result->next;
    }
};

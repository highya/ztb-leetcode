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
        if(head == NULL)
        	 return NULL;
        if(n<=0)
        	return head;
        ListNode  * p=head;
        ListNode * q=head;
        while(n>1)
        {
        	q=q->next;
        	if(q == NULL)
        	{
        		return NULL;
        	}
        	n--;
        }
        if(q->next==NULL)
        {
        	 ListNode * Head=new ListNode(0);
        	 Head->next=head->next;
        	 delete head;
        	 return Head->next;
        }
        while(q->next->next!=NULL)
        {
        	p=p->next;
        	q=q->next;
        }
        q=p->next;
        p->next=q->next;
        delete q;
        return head;
    }
};

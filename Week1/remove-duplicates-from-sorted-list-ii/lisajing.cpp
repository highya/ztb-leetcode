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
    	if( (head == NULL) || (head->next==NULL) )
    	{
    		return head;
    	}
        ListNode *Head =new ListNode(-1000);
        Head->next = head;
        ListNode * p=Head;
        ListNode *q=p->next;
        ListNode *r;
        int current=p->val;
        int dup=0;
        while(q->next!=NULL)
        {  
        	if((current != q->val)&&(q->val!=q->next->val) )
        	{
        		dup=0;
        		p->next=q;
        		p=p->next;
        		q=q->next;
        		current=p->val;
        	}   	
        	else if(q->val==q->next->val)
        		{
        			dup=1;
        			current = q->val;
        			while( (q->next!=NULL)&&(current == q->val) )
        			{
        				r=q;
        				p->next=q->next;
        				q=q->next;
        				delete r;
        			}
        		}
        }
        if(current!=q->val)
        {
        	dup=0;
       	}
          if(dup==1) 
        	{
        		p->next=q->next;
        		delete q;
        		return Head->next;
        	}
        	else 
        	{
        		p->next=q;
        		return Head->next;
        	}
    }
};

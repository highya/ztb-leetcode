class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *cur,*tail;
        
        cur=head;
        tail=head->next;

        for(int i=1;i<n;i++)
	        tail=tail->next;

        if(tail==NULL)
        {
	        return head->next;
        }
        else
        {
        	tail=tail->next;
        
        	while(tail)
        	{
        		cur=cur->next;
        		tail=tail->next;
        	}
        	
        	cur->next=cur->next->next;
        	return head;
        }
    }
};

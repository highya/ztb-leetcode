class Solution {
public:
    ListNode *deldup(ListNode **pre,ListNode **head,ListNode **cur,int flag)
    {
    	if(flag==0)
    	{
    		if(*pre==NULL) *head=(*cur)->next;
    		else (*pre)->next=(*cur)->next;
    	}
    }
    
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *pre=NULL;
        ListNode *cur=head;
        int flag=1;
        
        while(cur!=NULL&&cur->next!=NULL)
        {
        	if(cur->val ^ cur->next->val)//
        	{
        		if(flag==0)
        		{
        			deldup(&pre,&head,&cur,flag);
        		}
                else
                {
                    pre=cur; 
                }
        		flag=1;
        	}
        	else
        	{
        		flag=0;
        	}
        	cur=cur->next;
        }
        
        deldup(&pre,&head,&cur,flag);
        return head;
    }
};

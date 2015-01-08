class Solution {
public:  
    ListNode *deleteDuplicates(ListNode *head) {  
        ListNode *pre,*now,*Head;  
        if(!head||!head->next)return head;  
        Head=new ListNode(-1);  
        Head->next=head;  
        pre=Head;  
        now=head;  
        while(now&&now->next)  
        {  
            if(now->val == now->next->val)  
            {  
                while(now->next && now->val == now->next->val)  
                {  
                    now=now->next;  
                }  
                pre->next=now->next;  
                now=now->next;  
            }  
            else   
            {  
                pre=now;  
                now=now->next;  
            }  
        }  
        head=Head->next;  
        delete(Head);  
        return head;  
    }  
};

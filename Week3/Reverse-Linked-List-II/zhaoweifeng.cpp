class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *rhead=head,*rtail,*tail=head,*cur=NULL,*next=NULL;
        
        for(int i=1;i<m-1;i++) tail=tail->next;
        
        if(m>1) rhead = tail->next;
        
        rtail=rhead;
        cur=rhead->next;
        
        for(int i=m;i<n;i++) {
            next=cur->next;
            cur->next = rhead;
            rhead=cur;
            cur=next;
        }
        
        if(m==1) {
            rtail->next = cur;
            return rhead;
        }
        else {
            tail->next = rhead;
            rtail->next = cur;
            return head;
        }
    }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result=l1,*cur;
        int carry=0;
        int tmp;
        
        while(l1!=NULL&&l2!=NULL)
        {
            cur=l1;
            
            tmp = (carry + l1->val + l2->val);
            cur->val = tmp % 10;
            carry = tmp / 10;
            
            l1=l1->next;
            l2=l2->next;
        }
        
        if(l1==NULL) cur->next=l2;
        if(l2==NULL) cur->next=l1;
        
        while(cur->next!=NULL&&carry!=0)
        {
            cur=cur->next;
            
            tmp = carry + cur->val;
            cur->val = tmp % 10;
            carry = tmp / 10;
        }
        
        if(carry!=0)
        {
            ListNode *ln = new ListNode(1);
            cur->next=ln;
        }
        
        return result;
    }
};

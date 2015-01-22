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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head=new ListNode(0);
        ListNode *p=l1;
        ListNode *q=l2;
        ListNode *n,*t=head;
        int cflag=0;
        while(p&&q)
        {
            n=new ListNode(0);
            int s=(p->val+q->val+cflag);
            if (s>=10){
                cflag=1;
            }else{
                cflag=0;
            }
            n->val=s%10;
            t->next=n;
            t=n;
            p=p->next;
            q=q->next;
        }
        while(p){
            n=new ListNode(0);
            int s=(p->val+cflag);
            if (s>=10){
                cflag=1;
            }else{
                cflag=0;
            }
            n->val=s%10;
            t->next=n;
            t=n;
            p=p->next;
        }
        while(q){
            n=new ListNode(0);
            int s=(q->val+cflag);
            if (s>=10){
                cflag=1;
            }else{
                cflag=0;
            }
            n->val=s%10;
            t->next=n;
            t=n;
            q=q->next;
        }
        if(cflag)
        {
            n=new ListNode(1);
            t->next=n;
        }
        return head->next;
    }
};

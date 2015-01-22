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
        ListNode *temp=new ListNode(0);
        ListNode *res=temp;
        bool plus=false;   //记录进位
        while(l1&&l2){
            ListNode *l3=new ListNode(0);
            temp->next=l3;
            l3->val=l1->val+l2->val;
            if(plus)
                l3->val++;
            if(l3->val>9){
                l3->val-=10;
                plus=true;
            }
            else
                plus=false;
            l1=l1->next;
            l2=l2->next;
            temp=temp->next;
        }
        while(l1){
            ListNode *l3=new ListNode(0);
            temp->next=l3;
            l3->val=l1->val;
            if(plus)
                l3->val++;
            if(l3->val>9){
                l3->val-=10;
                plus=true;
            }
            else
                plus=false;
            temp=temp->next;
            l1=l1->next;
        }
        while(l2){
            ListNode *l3=new ListNode(0);
            temp->next=l3;
            l3->val=l2->val;
            if(plus)
                l3->val++;
            if(l3->val>9){
                l3->val-=10;
                plus=true;
            }
            else
                plus=false;
            temp=temp->next;
            l2=l2->next;
        }
        if(plus){
            ListNode *l3=new ListNode(0);
            temp->next=l3;
            l3->val=1;
        }
        return res->next;
    }
};

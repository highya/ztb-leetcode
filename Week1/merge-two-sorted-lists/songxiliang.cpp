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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {//increment order?
        
        ListNode * p1 = l1;
        ListNode * p2 = l2;
        ListNode * head = NULL;
        ListNode * pCurrent = NULL;
        
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1&&l2){//chose the head node
            if(l1->val < l2->val){
                pCurrent = head = l1;
                p1 = l1->next;
            }
            else{
                pCurrent = head = l2;
                p2 = l2->next;
            }
        }
       
        while(p1&&p2){//when not null,travel
            if(p1->val < p2->val){
                pCurrent->next = p1;
                pCurrent = p1;
                p1 = p1->next;
            }
            else{
                pCurrent->next = p2;
                pCurrent = p2;
                p2 = p2->next;
            }
        }
        if(p1){
            pCurrent->next = p1;
        }
        else{
            pCurrent->next = p2;
        }
        //l1 = l2 = NULL;
        return head;
    }
};

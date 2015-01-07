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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *l3=(ListNode*)malloc(sizeof(ListNode));
        ListNode *p3=l3;
        while(l1&&l2){
            if(l1->val<l2->val){
                p3->next=l1;
                l1=l1->next;
            }else{
                p3->next=l2;
                l2=l2->next;
            }
            p3=p3->next;
        }
        if(l1){
            p3->next=l1;
        }
        if(l2){
            p3->next=l2;
        }
        return l3->next;
    }
};

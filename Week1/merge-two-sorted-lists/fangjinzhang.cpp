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
        if (l1 == NULL){
            return l2;
        }
        if (l2 == NULL){
            return l1;
        }
        ListNode *l3, *ret;
        if (l1->val < l2->val){
            l3 = l1;
            l1 = l1->next;
        }else{
            l3 = l2;
            l2 = l2->next;
        }
        ret = l3;
        while (l1 != NULL && l2 != NULL){
            if (l1->val < l2->val){
                l3->next = l1;
                l3 = l3->next;
                l1 = l1->next;
            }else{
                l3->next = l2;
                l3 = l3->next;
                l2 = l2->next;
            }
        }
        
        if (l1 != NULL){
            l3->next = l1;
        }else{
            l3->next = l2;
        }
        
        return ret;
    }
};

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
        if (l1 != NULL && l2 != NULL){
            if (cmp(l1, l2)){
                l3 = l1;
                next(l1);
            }else{
                l3 = l2;
                next(l2);
            }
            ret = l3;
            
            while (l1 != NULL && l2 != NULL){
                if (cmp(l1, l2)){
                    l3->next = l1;
                    next(l1);
                    next(l3);
                }else{
                    l3->next = l2;
                    next(l2);
                    next(l3);
                }
            }
        }
        
        if (l1 != NULL){
            l3->next = l1;
        }else if (l2 != NULL){
            l3->next = l2;
        }else{
            ret = NULL;
        }
        
        return ret;
    }
    
    bool cmp(ListNode *l1, ListNode *l2){
        return l1->val < l2->val;
    }
    
    void next(ListNode * &l1){
        l1 = l1->next;
    }
};
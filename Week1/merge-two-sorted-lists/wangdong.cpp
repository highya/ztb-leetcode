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
        
        if(l1 == NULL && l2 == NULL) {
            return NULL;
        }
        
        if(l1 == NULL) {
            return l2;
        }
        
        if(l2 == NULL) {
            return l1;
        }
        
        ListNode *l = NULL;
        
        if(l1->val < l2->val) {
            l = l1;
            l->next = mergeTwoLists(l1->next,l2);
        }
        
        else {
            l = l2;
            l->next = mergeTwoLists(l2->next,l1);
        }
        
        return l;
        
    }
};

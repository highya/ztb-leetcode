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
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *newhead = new ListNode(0); 
        ListNode *cursor = newhead;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                cursor->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                cursor->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            cursor = cursor->next;
        }
        if(l1!=NULL)
            cursor->next = l1;
        else if(l2!=NULL)
            cursor->next = l2;
        return newhead->next;
            
    }
};

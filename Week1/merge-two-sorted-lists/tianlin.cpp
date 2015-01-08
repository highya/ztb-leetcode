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
        if(l1==NULL && l2==NULL)
            return NULL;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *result_head = new ListNode(0);
        ListNode *cursor = result_head;
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->val <= p2->val)
            {
                cursor->next = p1;
                p1 = p1->next;
            }
            else
            {
                cursor->next = p2;
                p2 = p2->next;
            }
            cursor = cursor->next;
        }
        if(p1==NULL && p2!=NULL)
            cursor->next = p2;
        else if(p2==NULL && p1!=NULL)
            cursor->next = p1;
        return result_head->next;
    }
};

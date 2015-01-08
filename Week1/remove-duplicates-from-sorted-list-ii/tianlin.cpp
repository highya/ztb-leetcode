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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode *newhead = new ListNode(0);
        ListNode *cursor,*p_former,*p_latter;
        cursor = newhead;
        p_former = head;
        p_latter = p_former -> next;
        bool flag = false; //元素不重复
        while(p_latter!=NULL)
        {
            if(p_latter->val == p_former->val)
                flag = true;
            else if(flag)
            {
                p_former = p_latter;
                flag = false;
            }
            else
            {
                cursor->next = new ListNode(p_former->val);
                cursor = cursor->next;
                p_former = p_latter;
            }
            p_latter = p_latter->next;
            if(p_latter == NULL && !flag)
                cursor->next = new ListNode(p_former->val);
        }
        return newhead->next;
    }
};

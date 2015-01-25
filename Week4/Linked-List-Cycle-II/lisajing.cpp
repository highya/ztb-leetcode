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
    ListNode *detectCycle(ListNode *head) {
        if(!head) 
            return NULL;
        ListNode * fast = head;
        ListNode * slow = head;
        while((fast) && (fast -> next) )
        {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)
            {
                ListNode * other = head;
                while(other != slow)
                {
                    other = other -> next;
                    slow = slow ->next;
                }
                return other;
            }
        }
        return NULL;
    }
};

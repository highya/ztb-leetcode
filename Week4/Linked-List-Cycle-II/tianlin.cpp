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
        ListNode *fast = head,*slow = head;
        while(1){
			if(fast == NULL || fast->next == NULL)
				return NULL;
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                break;
        }
        ListNode *place = fast,*check = head;
        while(check != slow){
            check = check->next;
            slow = slow->next;
        }
        return slow;
    }
};

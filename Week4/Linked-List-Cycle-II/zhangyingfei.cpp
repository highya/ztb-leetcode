class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *detect = head;
        bool flag = false;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == detect) return detect;
            if(fast == slow) flag = true;
            if(flag) detect = detect->next;
        }
        return NULL;
    }
};

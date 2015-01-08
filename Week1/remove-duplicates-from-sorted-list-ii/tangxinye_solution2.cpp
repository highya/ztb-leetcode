class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *now = head->next;
        if (head->val == now->val) {
            while (now && head->val == now->val) {
                ListNode *tmp = now;
                now = now->next;
                delete tmp;
            }
            delete head;
            return deleteDuplicates(now);
        } else {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};

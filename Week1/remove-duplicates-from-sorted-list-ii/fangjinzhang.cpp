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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p = head;
        int count = 0;
        while (p != NULL){
            count++;
            p = p->next;
        }
        int i = count - n;
        ListNode *to_del;
        if (i == 0){
            to_del = head;
            head = head->next;
        }else{
            p = head;
            while (--i > 0){
                p = p->next;
            }
            to_del = p->next;
            p->next = to_del->next;
        }
        delete to_del;
        return head;
    }
};
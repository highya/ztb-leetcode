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
        ListNode *p = head, *q, *to_del;
        int val;
        
        if (head == NULL || head->next == NULL){
            return head;
        }
        if (head->val == head->next->val){
            val = head->val;
            to_del = head;
            while (head->next != NULL && head->next->val == val){
                head = head->next;
            }
            q = head;
            head = head->next;
            q->next = NULL;
            while (to_del != NULL){
                q = to_del;
                to_del = to_del->next;
                delete q;
            }
            return deleteDuplicates(head);
        }
        
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        ListNode *p3 = head->next->next;
        
        while (p2 != NULL && p3 != NULL){
            if (p2->val != p3->val){
                p1 = p2;
                p2 = p3;
                p3 = p3->next;
                continue;
            }
            to_del = p2;
            val = p2->val;
            while (p3->next != NULL && p3->next->val == val){
                p3 = p3->next;
            }
            q = p3;
            p3 = p3->next;
            q->next = NULL;
            while (to_del != NULL){
                q = to_del;
                to_del = to_del->next;
                delete q;
            }
            p1->next = p2 = p3;
            p3 = p2 == NULL ? NULL : p2->next;
        }
        
        return head;
    }
};
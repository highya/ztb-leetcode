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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        
        ListNode tmp(0);
        ListNode *p = &tmp;
        p->next = head;
        
        int i = 0;
        while (++i < m){
            p = p->next;
        }
        ListNode *pre = p;
        p = p->next;
        
        for (i = 1; i <= n - m; ++i){
            ListNode *q = p->next->next;
            p->next->next = pre->next;
            pre->next = p->next;
            p->next = q;
        }
        
        return tmp.next;
    }
};

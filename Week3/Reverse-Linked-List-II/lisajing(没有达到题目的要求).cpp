/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    //没有达到题目的要求！！！Do it in-place and in one-pass.
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode * Head = new ListNode(0);
        Head -> next = head; //very useful!
        ListNode * m_fixed = head;
        ListNode * m_pre = Head;
        ListNode * n_fixed = head;
        ListNode * n_pre = Head;
        for(int i = 1;i < m  ; i++)
        {
            m_fixed = m_fixed -> next;
            m_pre = m_pre -> next;
        }
        for(int i = 1;i < n ; i++)
        {
            n_fixed = n_fixed -> next;
            n_pre = n_pre -> next;
        }
        m_pre -> next = n_fixed;
        ListNode *p = m_fixed;
        if(!m_fixed -> next)
            return Head -> next;
        ListNode * q = p -> next;
        ListNode * n_next = n_fixed -> next;
        while(p != n_fixed)
        {
            if(!q)
                break;
            ListNode *temp = q -> next;
            q -> next = p;
            p = q;
            q = temp;
        }
        m_fixed -> next = n_next;
        return Head -> next;
    }
};

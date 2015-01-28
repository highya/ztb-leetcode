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
        ListNode * Head = new ListNode(0);
        Head -> next = head; //very useful!
        ListNode * m_fixed = head;
        ListNode * m_pre = Head;
        int i = 1;
        for(;i < m  ; i++)
        {
            m_fixed = m_fixed -> next;
            m_pre = m_pre -> next;
        }
        ListNode *p = m_fixed;
        ListNode *q = p ->next;
        for(;i < n; i++)
        {
            if(!q)
            {
                m_fixed -> next = NULL;
                return Head->next;
            }
            ListNode *temp = q -> next;
            q -> next = p;
            p = q;
            q = temp;
        }
        m_pre -> next = p;
        m_fixed -> next = q;
        return Head -> next;   
    }
};

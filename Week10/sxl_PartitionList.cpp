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
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL) return head;
        //申请一个头节点
        ListNode *leader = new ListNode(INT_MIN);
        leader->next = head;
        ListNode *p = head, *q = head, *pre_p = leader, *pre_q = leader;
        //p指向第一个 >=x的节点，q指向p之后的第一个 <x的节点
        while(p->val < x )
        {
            pre_p = p;
            p = p->next;
            if(!p) return leader->next;
        }
        q = p;
        pre_q = pre_p;
        while(q->val >= x)
        {
            pre_q = q;
            q = q->next;
            if(!q) return leader->next;
        }
        
        //将有效的q插入到p之前
        while(q)
        {
            if(q->val < x)
            {
                pre_q->next = q->next;
                pre_p->next = q;
                q->next = p;
                pre_p = q;
                q = pre_q->next;
            }else
            {
                pre_q = q;
                q = q->next;
            }
        }
        delete leader;
        return leader->next;
  
    }
};

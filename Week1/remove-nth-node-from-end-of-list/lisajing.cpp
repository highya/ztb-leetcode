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
        if(head == NULL)
        	 return NULL;
       
        ListNode *p=new ListNode(0);
        ListNode *q;
        p ->next = head;
        q=p;
        int count=0;
        while(q ->next  != NULL)
        {
        	count ++;
        	q = q->next;
        }
       //判断n的合理范围
       if( (n <= 0) ||(n > count) )
        	return NULL;
       //如果删除到头结点
        if(n == count)
        {
        	q = head;
           p->next = q->next;
        	delete q;
        	head = p->next;
        	return head;
        }
       //删除非头结点的其余结点
        p = head;
        q = head->next;
        for(int i=1;i<count-n;i++)
        {
        	p=p->next;
        	q=q->next;
        }
        p->next=q->next;
        delete q;
        return head;
    }
    
};

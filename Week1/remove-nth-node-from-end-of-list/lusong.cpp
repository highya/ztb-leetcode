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
        int num = 0;
        ListNode *p = *q = head;

        ListNode *pre;
        ListNode *headpre = new ListNode(0);                                  
        pre = headpre;                                  //pre 是要删除的q节点的前一个节点
        headpre->next = head;
        
        if (n <= 0 || head ==NULL) return head;
        while(p->next && num < n-1 ){
            p = p->next;
            num++;
        }
        if(num < n-1) return head;                      //整个链表没有n个节点
        while(p->next){
            p = p->next;
            pre = q;
            q = q->next;
        }
        pre->next = q->next;
        return headpre->next;
    }
};

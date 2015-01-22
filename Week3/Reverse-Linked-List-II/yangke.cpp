/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public
    ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode  hh=(ListNode )malloc(sizeof(ListNode));
        ListNode  h, t, p, q;
        hh-next=head;
        p=hh;
        for(int i=0;im-1;i++,p=p-next);
        q=p-next;
        h=p;
        t=q;
        for(int j=m;j=n&&q!=NULL;j++)
        {
            p=q;
            q=q-next;
            p-next=h-next;
            h-next=p;
        }
        t-next=q;
        return hh-next;
    }
};

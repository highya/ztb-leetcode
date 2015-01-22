class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *vhead = new ListNode(0);
        vhead->next = head;
        ListNode *nodem_pre = vhead;
        ListNode *cur,*post;
        int i;
        
        for(i = 1; i < m; i++){
            nodem_pre = nodem_pre->next;
        }
        
        cur = nodem_pre -> next;
        for (i = m; i < n; i++){
            post = cur->next;
            cur->next = post->next;
            post->next = nodem_pre->next;
            nodem_pre->next = post;
        }
        
        return vhead -> next;
    }
};

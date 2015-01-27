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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p;
        ListNode *q;
        ListNode *tag;
        p=q=head;
        bool has_circle=false;
        while(p&&q&&q->next)
        {
            p=p->next;
            q=q->next->next;
            if(p==q){
                has_circle=true;
                break;
            }
        }
        if(!has_circle){
            return NULL;
        }else{
            p=head;
            while(p!=q){
                p=p->next;
                q=q->next;
            }
            return p;
        }
    }
};

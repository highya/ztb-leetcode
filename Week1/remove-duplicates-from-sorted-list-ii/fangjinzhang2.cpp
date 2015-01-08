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
        ListNode tmp_head(0);
        ListNode *p1, *p2, *p3, *to_del;
        tmp_head.next = p2 = head;
        p1 = &tmp_head;
        
        while (p2 != NULL && (p3 = p2->next) != NULL){
            if (p2->val != p3->val){
                p1 = p2;
                p2 = p3;
                continue;
            }
            
            int val = p2->val;
            while (p3->next != NULL && p3->next->val == val){
                p3 = p3->next;
            }
            to_del = p2;
            p2 = p3->next;
            p1->next = p2;
            p3->next =NULL;
            del(to_del);
        }
        
        return tmp_head.next;
    }
    
    void del(ListNode *to_del){
        ListNode *p;
        while (to_del){
            p = to_del;
            to_del = to_del->next;
            delete p;
        }
    }
};

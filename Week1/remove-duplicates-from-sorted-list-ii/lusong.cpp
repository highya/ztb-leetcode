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
        ListNode *headprev = new ListNode(0);
        ListNode *pre,*cur; 
        headprev->next = cur = head;
        pre = headprev;
        
        if (head==NULL || head->next ==NULL) return head;
        while(cur && cur->next){
            if(cur->val != cur->next->val) {
                pre->next = cur;
                pre = pre->next;
                cur = cur->next;
            }
            else{
                while(cur->next && cur->val == cur->next->val) cur = cur->next;
                pre->next = cur->next;
                cur = cur->next;
            }
        }
        
        return headprev->next;
        
    }
};

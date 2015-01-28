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
        ListNode *onestep,*twostep,*res;
        onestep = twostep = res = head;
        if(head == NULL || head->next == NULL) 
            return NULL;
        while(twostep && twostep->next){
            onestep = onestep->next;
            twostep = twostep->next->next;
            if(onestep == twostep)
                break;
        }
        if(onestep == twostep) {
            while(res != onestep){
                res = res->next;
                onestep = onestep->next;
            }
            return res;
        }
        else return NULL;
    }
};

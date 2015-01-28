/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return head;
        RandomListNode *curr = head;
        while(curr) {
            RandomListNode *new_node = new RandomListNode(curr->label);
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next;
        }
        
        curr = head;
        while(curr) {
            curr->next->random = curr->random==NULL ? NULL:curr->random->next;
            curr = curr->next->next;
        }
        
        RandomListNode *new_head = head->next;
        RandomListNode *ncurr = head->next;
        curr = head;
        while(ncurr) {
            curr->next = ncurr->next;
            curr = ncurr->next;
            if(curr) {
                ncurr->next = curr->next;
                ncurr = curr->next;
            }
            else {
                ncurr->next = NULL;
                ncurr = NULL;
            }
        }
        return new_head;
    }
};

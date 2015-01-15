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
        if (head == NULL) return NULL;
        
        RandomListNode *p = head;
        RandomListNode result(0);
        RandomListNode *q = &result;
        unordered_map<RandomListNode *, RandomListNode *> mapping;
        while (p){
            RandomListNode *node = new RandomListNode(p->label);
            mapping[p] = node;
            q->next = node;
            q = node;
            p = p->next;
        }
        
        p = head;
        q = result.next;
        while (p){
            if (p->random){
                q->random = mapping[p->random];
            }
            p = p->next;
            q = q->next;
        }
        
        return result.next;
    }
};

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
        map <RandomListNode * ,RandomListNode *> node_random;
        RandomListNode *Head = new RandomListNode(0);
        Head -> next = head;
        RandomListNode *Head2=new RandomListNode(0);
        RandomListNode *p = Head -> next;
        RandomListNode *q = Head2;
        while(p != NULL)
        {
             RandomListNode *newnode = new RandomListNode(p -> label);
             q -> next = newnode;
             q = q -> next;
             node_random[p] = q;
             p = p -> next;
        }
        p = Head -> next;
        q = Head2 ->next;
        while(p != NULL)
        {
            q -> random = node_random[p -> random];
            p = p -> next;
            q = q -> next;
        }
        return Head2 -> next;
    }
};

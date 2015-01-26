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
        map<RandomListNode*,RandomListNode*> mp;
        RandomListNode* h=new RandomListNode(0);
        RandomListNode* t=h;
        for(RandomListNode*p=head;p!=NULL;p=p->next)
        {
            t->next=new RandomListNode(p->label);
            mp[p]=t->next;
            t=t->next;
        }
        for(RandomListNode *p=h->next,*q=head;p!=NULL;p=p->next,q=q->next)
        {
            p->random=mp[q->random];
        }
        return h->next;
        
    }
};

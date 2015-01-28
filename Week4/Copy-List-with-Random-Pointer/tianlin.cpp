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
        if(head==NULL)
            return NULL;
        RandomListNode *cursor = head;
        while(cursor != NULL){
            RandomListNode *newNode = new RandomListNode(cursor->label);
            newNode->next = cursor->next;
            cursor->next = newNode;
            cursor = cursor->next->next;
        }
        cursor = head;
        while(cursor != NULL){
            cursor->next->random = (cursor->random == NULL) ? NULL : cursor->random->next;
            cursor = cursor->next->next;
        }
        RandomListNode *newHead = head->next;
        RandomListNode *p = head;
        RandomListNode *q = head->next;
        while(p != NULL){               //此处重点注意不能改变又来链表的状态
            p->next = q->next;
            q->next = (p->next == NULL) ? NULL : p->next->next;
            p = p->next;
            q = q->next;
        }
        return newHead;
    }
};

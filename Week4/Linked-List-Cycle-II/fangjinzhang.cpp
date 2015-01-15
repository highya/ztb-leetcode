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
        if (head == NULL || head->next ==NULL) return NULL;
        
        ListNode *p1, *p2, *p3;
        p1 = head;
        p2 = head->next;
        int count1 = 0;
        bool hasCycle = false;
        while (p2 && (p3 = p2->next)){
            if (p2 == p1 || p3 == p1){
                hasCycle = true;
                break;
            }
            p2 = p3->next;
            p1 = p1->next;
            ++count1;
        }
        
        if (hasCycle == false) return NULL;
        if (p1->next == p1) return p1;
        
        p2 = p1;
        p3 = p1->next;
        p1->next = NULL;
        p1 = p3;
        int count2 = 0;
        while (p1 = p1->next)
            ++count2;
        
        int count;
        ListNode *result = head;
        p1 = p3;
        if (count1 > count2){
            count = count1 - count2;
            while (count--) result = result->next;
        }else if (count1 < count2){
            count = count2 - count1;
            while (count--) p1 = p1->next;
        }
        
        while (p1 != result){
            p1 = p1->next;
            result = result->next;
        }
        
        p2->next = p3;
        return result;
    }
};

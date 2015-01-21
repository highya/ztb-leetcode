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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* pointer1 = l1,*pointer2 = l2;
        int addNext = 0;
        ListNode* head = new ListNode(0);
        ListNode *cursor = head;
        while(pointer1!=NULL || pointer2!=NULL){
            int num1 = (pointer1==NULL) ? 0 : pointer1->val;
            int num2 = (pointer2==NULL) ? 0 : pointer2->val;
            ListNode* newNum = new ListNode((num1+num2+addNext)%10);
            cursor->next = newNum;
            addNext = (num1+num2+addNext)/10;
            pointer1 = (pointer1==NULL) ? NULL : pointer1->next;
            pointer2 = (pointer2==NULL) ? NULL : pointer2->next;
            cursor = cursor->next;
        }
        if(addNext)
            cursor->next = new ListNode(addNext);
        return head->next;
    }
};

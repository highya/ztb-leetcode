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
        ListNode tmp(0);
        ListNode *l3 = &tmp;
        int flag = 0;//进位, 5+7, flag=1
        int r;//相加的结果，注意是位，5+7, r=2
        while (l1 && l2){
            cal(l1->val, l2->val, r, flag);
            l3->next = new ListNode(r);
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode *l4 = l1 == NULL ? l2 : l1;
        while (l4){
            cal(l4->val, 0, r, flag);
            l3->next = new ListNode(r);
            l3 = l3->next;
            l4 = l4->next;
        }
        if (flag != 0){
            l3->next = new ListNode(flag);
            l3->next->next = NULL;
        }
        
        return tmp.next;
    }
    
    void cal(int a, int b, int &r, int &flag){
        r = a + b + flag;
        if (r >= 10){
            r = r % 10;
            flag = 1;
        }else {
            flag = 0;
        }
    }
};

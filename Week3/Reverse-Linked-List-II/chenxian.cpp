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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *left=head;
        ListNode *right=head;
        for(int i=1;i<m;i++){
            left=left->next;
            right=right->next;
        }
        int step=0;   //记录第几次交换
        ListNode *right2=right;
        while(2*step<n-m){
            right=right2;
            for(int i=m;i<n-step;i++){   //每次从m开始
                right=right->next;
            }
            int temp;
            temp=left->val;
            left->val=right->val;
            right->val=temp;
            left=left->next;
            step++;
        }
        return head;
    }
};

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int count=0;
        ListNode *temp=head;
        
        //遍历计数（要先遍历感觉好若。。）
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        
        temp=head;
        //删除倒数第n项（第count+1-n项）
        if(n==count)
            return head->next;
        for(int i=2;i<count+1-n;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};

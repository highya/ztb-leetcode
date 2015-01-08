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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *res=new ListNode(0);
        
        //pre指向当前的元素，并将pre->next指向l1和l2中较小的元素
        ListNode *pre=res;
        while((l1!=NULL)&&(l2!=NULL)){
            if(l1->val<l2->val){
                pre->next=l1;
                pre=l1;
                l1=l1->next;
            }
            else{
                pre->next=l2;
                pre=l2;
                l2=l2->next;
            }
        }
        
        //把另一个链表多余的部分链接在后面
        if(l1==NULL)
            pre->next=l2;
        else
            pre->next=l1;
        
        return res->next;
    }
};

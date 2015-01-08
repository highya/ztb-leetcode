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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
            
        //定义链表头head2，head2->next指向head
        ListNode *head2=new ListNode(0);
        ListNode *pre=head2;
        head2->next=head;
        ListNode *temp=head;
        
        //flag用来记录是否有数值相同的项
        bool flag=false;
        
        //遍历链表
        while(temp->next!=NULL){
            flag=false;
            //遇到数值相同的项后继续遍历，直到数值不相同为止
            while(temp->val==temp->next->val){
                flag=true;
                temp=temp->next;
                //如果在遍历时发现已经到链表末尾，就直接返回
                if(temp->next==NULL){
                    pre->next=NULL;
                    return head2->next;
                }
            }
            //根据是否遇到了数值相同的项，进行对应的操作
            if(flag){
                pre->next=temp->next;
                temp=temp->next;
            }
            else{
                pre=pre->next;
                temp=temp->next;
            }
        }
       return head2->next;
    }
};

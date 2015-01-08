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
        ListNode *result = new ListNode(0);
        ListNode *cur=result;
        
        while(l1!=NULL && l2!=NULL)
        {
            //选择较小值结点，并改变相应指针
            cur->next = l1->val < l2->val ? l1 : l2 ;
            l1->val < l2->val ? l1=l1->next : l2=l2->next ;
            cur=cur->next;
        }
        
        cur->next = l1==NULL ? l2 : l1;
        
    	return result->next;	
    }
};

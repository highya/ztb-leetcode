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
        if( (l1 == NULL) && (l2 == NULL) )
            return NULL;
        else if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        ListNode *p1;
        ListNode *p2;
        ListNode *l3=(l1->val < l2->val ? (p1=l1->next,p2=l2,l1) :(p2=l2->next,p1=l1,l2));
        ListNode *p3=l3;
    
        while( (p1 != NULL)  &&  ( p2 != NULL ))
        {
        	if(p1->val < p2->val)
       		{
        			p3->next = p1;
        			p3 = p3->next;
        			p1 = p1->next;
       		}
        	else
        	{
        		p3->next = p2;
        		p3 = p3->next;
        		p2 = p2->next;
        	}
        }
        
        if (p1 == NULL)
        	{
        		p3->next = p2;
        	}
        else if(p2 == NULL)
        	{
        		p3->next = p1;
        	}
        	return l3;
    }
    
};

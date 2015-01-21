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
		ListNode *result,*record,*pointer1,*pointer2;
		result = record = pointer1 = pointer2 = head;
		for(int i=1;i<m-1;i++){
			pointer1 = pointer1->next;
			record = record->next;
		}
		if(m != 1)
			pointer1 = pointer1->next;
		for(int j=1;j<n;j++)
			pointer2 = pointer2->next;
		if(m == 1)
			result = pointer2;
		while(pointer1 != pointer2){
			ListNode * tmp = pointer2->next;
			pointer2->next = pointer1;
			if(m!=1){
				record->next = record->next->next;
				pointer1->next = tmp;
				pointer1 = record->next;
			}
			else{
				ListNode* next = pointer1->next;
				pointer1->next = tmp;
				pointer1 = next;
			}
		}
		return result;
    }
};

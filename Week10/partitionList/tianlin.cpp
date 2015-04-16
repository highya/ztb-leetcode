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
    ListNode *partition(ListNode *head, int x) {
		if(head == NULL || head->next == NULL)	//对于空和只有一个成员的问题
            return head;
		ListNode new_Head(INT_MIN);
		ListNode* newHead = &new_Head;
		newHead->next = head;
		ListNode *cursor = newHead, *first_next_larger = newHead;
		while(cursor != NULL && cursor->next != NULL){     //对于头位置的问题
            if(cursor->val < x && cursor->next->val >= x){
                first_next_larger = cursor;
				break;
			}
			cursor = cursor->next;
        }
		while(cursor != NULL && cursor->next != NULL){     
            if(cursor->next->val < x){
				ListNode* cursorNext = cursor->next;
                cursor->next = cursor->next->next;	//后面指针调整
                cursorNext->next = first_next_larger->next;	//前面指针调整
                first_next_larger->next = cursorNext;	//前面指针调整
				first_next_larger = cursorNext;
            }
			else
				cursor = cursor->next;
        }
        return newHead->next;
    }
}; 

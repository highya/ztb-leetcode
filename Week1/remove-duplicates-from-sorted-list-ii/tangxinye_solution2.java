public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head==null||head.next==null)
        	return head;
        
        ListNode now= head.next;
        if(head.val==now.val){
        	while(now!=null&&head.val==now.val){
        		now=now.next;
        	}
        	return deleteDuplicates(now);
        }else {
			head.next=deleteDuplicates(head.next);
		}
        return head;
    }
}

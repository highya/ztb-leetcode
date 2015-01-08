public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
       if(head==null||head.next==null)
        	return head;
        ListNode helper = new ListNode(0);
        helper.next=head;
        ListNode pre= helper;
        ListNode now= head;
        while(now!=null){
        	while(now.next!=null&&pre.next.val==now.next.val){
        		now=now.next;
        	}
        	if(pre.next!=now){
        		pre.next=now.next;
        	}else{
        		pre=pre.next;
        	}
        	now=now.next;
        }
        return helper.next;
    }
}

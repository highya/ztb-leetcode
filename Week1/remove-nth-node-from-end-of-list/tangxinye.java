public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode helper=new ListNode(-1);
        helper.next=head;
        ListNode index=helper;
        ListNode real=helper;
        for(int i=0;i<n;i++){
        	index=index.next;
        }
        while(index.next!=null){
        	index=index.next;
        	real=real.next;
        }
        real.next=real.next.next;
        return helper.next;
    }
}

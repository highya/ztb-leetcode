public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast=head;  //快指针
        ListNode slow=head;  //慢指针
        while(fast!=null&&fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
            if(fast==slow){  //相遇
                slow=head;
                while(slow!=fast){
                    slow=slow.next;
                    fast=fast.next;
                }
                return fast;
            }
        }
        return null;
    }
}

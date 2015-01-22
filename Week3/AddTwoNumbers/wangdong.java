public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        
        ListNode result = new ListNode(-1);
        ListNode l3 = result;
        
        int sum = 0;
        while(l1 !=null || l2 !=null) {
            if(l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            
            if(l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }
            
            l3.next = new ListNode(sum % 10);
            sum = sum / 10;
            l3 = l3.next;
        }
        
        if(sum == 1){
            l3.next = new ListNode(1);
        }
        return result.next;
    }
}

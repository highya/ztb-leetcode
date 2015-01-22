public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        
        ListNode before , after, start, end;
        before = after = start = end = null;
        
        ListNode helper = head;
        
        for(int i = 1; i < m; i++) {
            before = helper;
            helper = helper.next;
        }
        
        start = end = helper;
        for(int i = m; i <= n; i++) {
            after = helper.next;
            helper.next = end;
            end = helper;
            helper = after;
        }
        
        if(before == null) {
            head = end;
        }
        else {
            before.next = end;
        }
        
        start.next = after;
        
        return head;
    }
}

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head ==null){
            return head;
        }
        ListNode slow = head;
        ListNode fast = head;
        ListNode begin = head;
        while( fast.next !=null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                while(begin != slow){
                    begin = begin.next;
                    slow = slow.next;
                }
                return begin;
            }
        }
        return null;
    }
}

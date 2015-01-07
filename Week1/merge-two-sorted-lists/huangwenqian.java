/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode L3=new ListNode(0);
        ListNode p3=L3;
        while(l1!=null&&l2!=null){
            if(l1.val<l2.val){
                p3.next=l1;
                l1=l1.next;
            }else{
                p3.next=l2;
                l2=l2.next;
            }
            p3=p3.next;
        }
        if(l1!=null){
            p3.next=l1;
        }else{
            p3.next=l2;
        }
        return L3.next;
    }
}

public class Solution {
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode merge= new ListNode(0);
        ListNode pre=merge;
        if(l1==null)
        	return l2;
        if(l2==null)
        	return l1;
        while(l1!=null&&l2!=null){
        	if(l1.val<=l2.val){
        		merge.next=l1;
        		l1=l1.next;
        	}else{
        		merge.next=l2;
        		l2=l2.next;
        	}
        	merge=merge.next;
        	
        }
        while(l1!=null){
        	merge.next=l1;
        	merge=merge.next;
        	l1=l1.next;
        }
        while(l2!=null){
        	merge.next=l2;
        	merge=merge.next;
        	l2=l2.next;
        }
     return pre.next;   
    }
	
}

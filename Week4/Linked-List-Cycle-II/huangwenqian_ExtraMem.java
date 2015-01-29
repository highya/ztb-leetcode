public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode curr=head;
        Map<ListNode,Integer>map=new HashMap<ListNode,Integer>();
        while(curr!=null){
            if(map.containsKey(curr)){
                return curr;
            }else{
                map.put(curr,1);
                curr=curr.next;
            }
        }
        return null;
    }
}

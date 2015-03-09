public class Solution {

    public ListNode merge2List(ListNode L1,ListNode L2){
        ListNode L3=new ListNode(0);  //虚拟头结点
        ListNode tmp=L3;
        while(L1!=null&&L2!=null){
            if(L1.val<L2.val){
                tmp.next=L1;tmp=tmp.next;
                L1=L1.next;
            }else{
                tmp.next=L2;tmp=tmp.next;
                L2=L2.next;
            }
        }
        if(L1!=null){
            tmp.next=L1;
        }else{
            tmp.next=L2;
        }
        return L3.next;
    }
    
    public ListNode mergeKLists(List<ListNode> lists) {
        if(lists.size()==0)return null;
        int i;ListNode tmp;
        while(lists.size()>=2){
            i=0;
            while(i<lists.size()-1){
                tmp=merge2List(lists.get(i),lists.get(i+1));
                lists.add(tmp);
                lists.remove(i);
                lists.remove(i);
            }
        }
        return lists.get(0);
    }
}

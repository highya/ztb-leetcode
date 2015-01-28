public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if(head==null)return null;
        
        //第一遍创建新结点并插入被复制节点后
        RandomListNode tmp,tail;
        RandomListNode curr=head;
        RandomListNode L=new RandomListNode(0);  //伪头结点
        while(curr!=null){
            tmp=new RandomListNode(curr.label);
            tmp.next=curr.next;
            curr.next=tmp;
            curr=curr.next.next;
        }
		
        //第二遍拷贝random
        curr=head;
        while(curr!=null){            //二三轮curr!=null省去if判断代码
            if(curr.random!=null){    
                curr.next.random=curr.random.next;
            }
            curr=curr.next.next;
        }
		
        //第三遍移出新节点，尾插法建新链表
        curr=head;tail=L;
        while(curr!=null){
            tail.next=curr.next;
            tail=tail.next;
            curr.next=curr.next.next;
            curr=curr.next;
        }
        return L.next;
    }
}

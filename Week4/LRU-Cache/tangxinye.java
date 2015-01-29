public class LRUCache {
    HashMap<Integer, Node> map;
    Node head, tail;
    int size;
   public LRUCache(int capacity) {
    	 map = new HashMap<Integer, Node>(capacity);
    	 size = capacity;
    	 head = new Node(-1, -1);
    	 tail = new Node(1, 1);
    	 head.next = tail;
    	 tail.pre = head;
    }
    
    public int get(int key) {
        if(map.containsKey(key)){
            Node p = map.get(key);
            putToHead(p);
            return p.val;
        }else{
            return -1;
        }
    }
    
    public void set(int key, int value) {
        if(map.containsKey(key)){
            Node p = map.get(key);
            p.val = value;
            putToHead(p);
        }else if(map.size() < size){
            Node newnode = new Node(key,value);
            putToHead(newnode);
            map.put(key,newnode);
        }else{
            
            Node newnode = new Node(key,value);
            putToHead(newnode);
            map.put(key,newnode);
            int end = deleteTail();
            map.remove(end);
        }
        
    }
    public void putToHead(Node p){
        if(p.pre != null && p.next != null){
            p.pre.next = p.next;
            p.next.pre = p.pre;
        }
        p.next = head.next;
        head.next.pre = p;
        head.next = p;
        p.pre = head;
    }
    public int deleteTail(){
        Node p = tail.pre;
        int key = p.key;
        
        p.pre.next = tail;
        tail.pre = p.pre;
        p.next = null;
        p.pre = null;
        return key;
    }
}
class Node{
    int key,val;
    Node pre,next;
    Node(int key,int val){
        this.key = key;
        this.val = val;
    }
}

public class LRUCache {
    int capacity=0;
    Map<Integer,Integer>map=new HashMap<Integer,Integer>();     //保存key和对应value的关系
    ArrayList<Integer>list=new ArrayList<Integer>();            //保存key,链表头是最近最少使用
    
    public LRUCache(int capacity) {
        this.capacity=capacity;
    }
    
    public int get(int key) {  //每get()一次都要调整一下
        if(!map.containsKey(key))return -1;
        int index=list.indexOf(key);
        list.remove(index);
        list.add(key);
        return map.get(key);
    }
    
    public void set(int key, int value) {
        if(map.containsKey(key)){    //原来有key则重置
            map.put(key,value);
            get(key);return;
        }
        if(list.size()==capacity){
            map.remove(list.get(0));
            list.remove(0);
        }
        list.add(key);
        map.put(key,value);
    }
}

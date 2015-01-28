struct PriorListNode
{
   int key;
   int value;
   PriorListNode(int key,int value):key(key),value(value){}
};
class LRUCache{
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        this -> size = 0;
    }
    
    int get(int key) {
        if(LRU_MAP.find(key) == LRU_MAP.end())
            return -1;
        else
        {
            list <PriorListNode> :: iterator pit = LRU_MAP[key];
            plist.splice(plist.begin(),plist,pit);
            LRU_MAP.erase(key);
            LRU_MAP[key] = plist.begin();
            return plist.begin() -> value;
        }
    }
    
    void set(int key, int value) {
        if(LRU_MAP.find(key) == LRU_MAP.end())
        {
            if(plist.size() == capacity)
            {
                LRU_MAP.erase(plist.back().key);
                plist.pop_back();
               plist.push_front(PriorListNode(key,value));
                LRU_MAP[key] = plist.begin();
            }
            else
            {
                size++;
                plist.push_front(PriorListNode(key,value));
                LRU_MAP[key] = plist.begin();
            }
        }
        else
        {
            LRU_MAP[key] -> value = value;
            list <PriorListNode> :: iterator pit = LRU_MAP[key];
            plist.splice(plist.begin(),plist,pit);
            LRU_MAP.erase(key);
            LRU_MAP[key] = plist.begin();
        }
    }
private:
    list <PriorListNode>  plist;
    unordered_map <int , list <PriorListNode> :: iterator> LRU_MAP;
    int capacity;
    int size;
};

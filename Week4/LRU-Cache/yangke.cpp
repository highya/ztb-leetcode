class LRUCache{
private:
    int size;
    int count=0;
    list<pair<int,int>> cache;
    map<int,list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        size=capacity;
    }
    int get(int key) {
        int ret_val=-1;
        map<int,list<pair<int,int>>::iterator>::iterator it=mp.find(key);
        if(it!=mp.end()){
            ret_val=it->second->second;
            pair<int,int> top_pair=*(it->second);
            cache.erase(it->second);
            cache.push_front(top_pair);
            mp[key]=cache.begin();
        }
        return ret_val;
    }
   
    void set(int key, int value) {
        map<int,list<pair<int,int>>::iterator>::iterator it=mp.find(key);
        pair<int,int> top_pair=make_pair(key,value);//creat a pair any way
        if(it!=mp.end()){//find the key
            cache.erase(it->second);
        }else{//key not exist
            if(count==size){//full
                int delkey=cache.back().first;
                map<int,list<pair<int,int>>::iterator>::iterator it=mp.find(delkey);
                cache.erase(it->second);
                mp.erase(it);
                count--;
            }
            count++;
        }
        cache.push_front(top_pair);
        mp[key]=cache.begin();
    }
        
};

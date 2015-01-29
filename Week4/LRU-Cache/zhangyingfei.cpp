class LRUCache{
    struct item_kv{
    int key;
    int value;
    item_kv(int k, int v):key(k), value(v){}
    };
    
    int m_cap;
    list<item_kv> m_list;
    unordered_map<int, list<item_kv>::iterator> m_map;
    
public:
    LRUCache(int capacity) {
        m_cap = capacity;
    }
    
    int get(int key) {
        if(m_map.find(key) == m_map.end()) return -1;
        m_list.splice(m_list.begin(), m_list, m_map[key]);
        m_map[key] = m_list.begin();
        return m_list.begin()->value;
    }
    
    void set(int key, int value) {
        if(m_map.find(key) != m_map.end()){  
            m_list.splice(m_list.begin(), m_list, m_map[key]);
            m_list.begin()->value = value;  
            m_map[key] = m_list.begin();         
        }  
        else if(m_list.size()<m_cap){  
            m_list.push_front(item_kv(key, value));  
            m_map[key] = m_list.begin();  
        }  
        else{  
            item_kv last = m_list.back();  
            m_list.pop_back();  
            m_map.erase(last.key);  
            m_list.push_front(item_kv(key, value));  
            m_map[key] = m_list.begin();  
        }  
    }
};

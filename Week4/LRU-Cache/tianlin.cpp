class LRUCache{  
public:
    struct Entry {
        int k = -1;
        int val = -1;
        Entry *pre = NULL;
        Entry *next = NULL;
        Entry(int key, int value):k(key),val(value){};
    };
    
    LRUCache(int capacity) : capacity_(capacity) {
        head_ = new Entry(-1,-1);
        tail_ = new Entry(-1,-1);
        tail_->pre = head_;
        head_->next = tail_;
    }
    
    ~LRUCache() {
        delete head_;
        delete tail_;
    }
     
    int get(int k) {
        auto it = Umap_.find(k);
        if(it != Umap_.end()){
            MoveToHead(it->second);
            return it->second->val;
        }
        return -1;
    }
    
    void set(int k, int v) {
        auto it = Umap_.find(k);
        if(it != Umap_.end()){
            MoveToHead(it->second);
            it->second->val = v;
            return;
        }
        Entry *newEntry = new Entry(k,v);
        AddToHead(newEntry);
        Umap_[k] = newEntry;
        if(Umap_.size() > capacity_)
            RemoveLastEntry();
    }

private:
    void AddToHead(Entry* p) {
        p->pre = head_;
        p->next = head_->next;
        head_->next->pre = p;
        head_->next = p;
    }
    
    void MoveToHead(Entry* p) {
        p->pre->next = p->next;
        p->next->pre = p->pre;
        AddToHead(p);
    }
    
    void RemoveLastEntry() {
        Entry *p = tail_->pre;
        p->pre->next = tail_;
        tail_->pre = p->pre;
        auto it = Umap_.find(p->k);
        Umap_.erase(it);
        delete(p);
    }
    
    int capacity_;
    Entry *head_;
    Entry *tail_;
    unordered_map<int ,Entry*> Umap_;
};

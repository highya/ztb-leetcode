struct Node{
    Node():next(NULL), pre(NULL){}
    Node(int pkey, int pval):key(pkey), value(pval), next(NULL), pre(NULL){}
    int key;
    int value;
    Node *next;
    Node *pre;
};


class LRUCache{
private:
    Node *newPtr;
    int capacity;
    int size;
    
    Node * findNode(int key){
        if (size == 0) return NULL;
        
        Node *p = newPtr;
        while (p->key != key){
            p = p->next;
            if (p == newPtr) break;
        }
        if (p->key == key) return p;
        else return NULL;
    }
    
    void removeNode(Node *p){
        if (!p || p == newPtr || p == newPtr->pre) return;

        p->pre->next = p->next;
        p->next->pre = p->pre;
    }
    
    void insertHead(Node *p){
        if (!p || p == newPtr) return;
        if (p == newPtr->pre){
            newPtr = p;
            return;
        }
        if (newPtr == NULL){
            newPtr = p;
            newPtr->next = newPtr->pre = newPtr;
        }else{
            p->pre = newPtr->pre;
            newPtr->pre->next = p;
            newPtr->pre = p;
            p->next = newPtr;
            newPtr = p;
        }
    }
public:
    LRUCache(int capacity) {
        newPtr = NULL;
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        Node *node = findNode(key);
        int result = node ? node->value : -1;
        removeNode(node);
        insertHead(node);
        return result;
    }
    
    void set(int key, int value) {
        Node *node = findNode(key);
        if (node){
            node->value = value;
            removeNode(node);
            insertHead(node);
        }else{
            if (size < capacity){
                size++;
                Node *node = new Node(key, value);
                insertHead(node);
            }else{
                Node *node = newPtr->pre;
                node->key = key;
                node->value = value;
                newPtr = node;
            }
        }
    }
};

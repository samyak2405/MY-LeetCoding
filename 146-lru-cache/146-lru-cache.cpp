class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node *next;
            node *prev;
            node(int _key,int _val){
                key = _key;
                val = _val;
            }
    };
    
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    
    int cap;
    unordered_map<int,node *> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node *newnode)
    {
        newnode->next = head->next;
        head->next->prev = newnode;
        head->next = newnode;
        newnode->prev = head;
        mp[newnode->key] = newnode;
    }
    
    void deletenode(node *delnode)
    {
        mp.erase(delnode->key);
        delnode->next->prev = delnode->prev;
        delnode->prev->next = delnode->next;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            node *newnode = mp[key];
            deletenode(newnode);
            addnode(newnode);
            return newnode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
            deletenode(mp[key]);
        if(mp.size()==cap)
            deletenode(tail->prev);
        addnode(new node(key,value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
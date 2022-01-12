struct node{
        int key,value,cnt;
        node *next,*prev;
        node(int _key,int _value){
            key = _key;
            value = _value;
            cnt = 1;
        }
    };
    struct List{
        int size;
        node *head,*tail;
        List(){
            head = new node(0,0);
            tail = new node(0,0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        
        void addFront(node *newnode)
        {
            node *temp = head->next;
            newnode->next = temp;
            newnode->prev = head;
            head->next = newnode;
            temp->prev = newnode;
            size++;
        }
        
        void removeNode(node *newnode)
        {
            node *delprev = newnode->prev;
            node *delnext = newnode->next;
            delprev->next = delnext;
            delnext->prev = delprev;
            size--;
        }
    };

class LFUCache {
    map<int, node *> keynode;
    map<int, List *> freqlist;
    int minfreq;
    int maxSizeCache;
    int curSize;
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minfreq = 0;
        curSize = 0;
    }
    
    void updateFreqListMap(node *newnode)
    {
        keynode.erase(newnode->key);
        freqlist[newnode->cnt]->removeNode(newnode);
        if(newnode->cnt==minfreq and freqlist[newnode->cnt]->size==0)
            minfreq++;
        
        List *nextHigherFreqlist = new List();
        if(freqlist.find(newnode->cnt+1)!=freqlist.end())
            nextHigherFreqlist = freqlist[newnode->cnt+1];
        
        newnode->cnt +=1;
        nextHigherFreqlist->addFront(newnode);
        freqlist[newnode->cnt] = nextHigherFreqlist;
        keynode[newnode->key] = newnode;
    }
    
    
    
    int get(int key) {
        if(keynode.find(key)!=keynode.end())
        {
            node *newnode = keynode[key];
            int val = newnode->value;
            updateFreqListMap(newnode);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0)
            return;
        if(keynode.find(key)!=keynode.end())
        {
            node *newnode = keynode[key];
            newnode->value = value;
            updateFreqListMap(newnode);
        }
        else
        {
            if(curSize == maxSizeCache)
            {
                List *listnode = freqlist[minfreq];
                keynode.erase(listnode->tail->prev->key);
                freqlist[minfreq]->removeNode(listnode->tail->prev);
                curSize--;
            }
            curSize++;
            minfreq = 1;
            List *listfreq = new List();
            if(freqlist.find(minfreq)!=freqlist.end())
            {
                listfreq = freqlist[minfreq];
            }
            
            node *newnode = new node(key,value);
            listfreq->addFront(newnode);
            keynode[key] = newnode;
            freqlist[minfreq] = listfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
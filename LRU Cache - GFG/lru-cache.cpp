// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    class node{
     public:
     int key;
      int val;
      node *next;
      node *prev;
      node(int _key,int _val)
      {
          key = _key;
          val = _val;
      }
    };
    
    int cap;
    unordered_map<int,node *> mp;
    
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node *newnode)
    {
        newnode->next = head->next;
        newnode->prev = head;
        head->next->prev = newnode;
        head->next = newnode;
        mp[newnode->key] = newnode;
    }
    
    void deletenode(node *delnode)
    {
        mp.erase(delnode->key);
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
    }
    
    int get(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            node *newnode = mp[key];
            deletenode(newnode);
            addnode(newnode);
            return newnode->val;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(mp.find(key)!=mp.end())
            deletenode(mp[key]);
        if(mp.size()==cap)
            deletenode(tail->prev);
        addnode(new node(key,value));
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
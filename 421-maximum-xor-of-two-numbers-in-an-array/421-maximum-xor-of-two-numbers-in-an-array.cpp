struct Node{
    Node *link[2] = {NULL};
    
    bool containsKey(int bit)
    {
        return link[bit]!=NULL;
    }
    
    void put(int bit,Node *node)
    {
        link[bit] = node;
    }
    
    Node *get(int bit)
    {
        return link[bit];
    }
};

class Trie{
  private:
    Node *root;
  public:
    
    Trie()
    {
        root = new Node();
    }
    
    void insert(int num)
    {
        Node *node = root;
        
        for(int i = 31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(!node->containsKey(bit))
                node->put(bit,new Node());
            node = node->get(bit);
        }
    }
    
    int findMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        
        for(int i = 31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(node->containsKey(1-bit))
            {
                maxNum |= (1<<i);
                node = node->get(1-bit);
            }
            else
                node = node->get(bit);
        }
        return maxNum;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        
        Trie *obj = new Trie();
        
        for(auto it:nums)
            obj->insert(it);
        
        for(auto it:nums)
            maxi = max(maxi,obj->findMax(it));
        
        return maxi;
        
    }
};
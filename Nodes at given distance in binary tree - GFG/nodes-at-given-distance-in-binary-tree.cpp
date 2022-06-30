// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
    
public:
    
    void findParent(Node *root,Node *&target,int tar,map<Node *,Node *> &mp)
    {
        if(!root)
            return;
        if(tar==root->data)
            target = root;
        if(root->left)
        {
            mp[root->left] = root;
            findParent(root->left,target,tar,mp);
        }
        if(root->right)
        {
            mp[root->right] = root;
            findParent(root->right,target,tar,mp);
        }
    }
    
    void findDist(Node *root,int k,set<Node *> &s1,map<Node *,Node *> &mp,vector<int> &res)
    {
        if(!root)
            return;
        if(s1.find(root)!=s1.end())
            return;
        s1.insert(root);
        if(k==0)
            res.push_back(root->data);
        if(root->left)
            findDist(root->left,k-1,s1,mp,res);
        if(root->right)
            findDist(root->right,k-1,s1,mp,res);
        Node *p = mp[root];
        if(p)
            findDist(p,k-1,s1,mp,res);
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int> res;
        set<Node *> s1;
        map<Node *,Node *> mp;
        if(!root)
            return res;
        Node *tar;
        findParent(root,tar,target,mp);
        findDist(tar,k,s1,mp,res);
        sort(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends
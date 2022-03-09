// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    void reverse(Node *&head)
    {
        Node *prev = NULL,*forward = NULL;
        Node *curr = head;
        while(curr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
    }
    
    Node* addOne(Node *head) 
    {
        if(!head)
            return new Node(1);
        reverse(head);
        int c = 1;
        Node *prev = NULL;
        Node *p = head;
        while(p and c)
        {
            p->data = p->data+c;
            if(p->data>=10)
            {
                c=1;
                p->data%=10;
            }
            else
                c=0;
            prev = p;
            p=p->next;
        }
        if(c==1)
        {
            Node *newnode = new Node(1);
            prev->next = newnode;
        }
        reverse(head);
        return head;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
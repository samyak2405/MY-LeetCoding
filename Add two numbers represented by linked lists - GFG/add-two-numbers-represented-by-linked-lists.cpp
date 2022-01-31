// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    void reversal(struct Node *&head)
    {
        struct Node *prev = NULL,*curr = head,*forward = NULL;
        
        while(curr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = forward;
        }
        
        head = prev;
    }
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        if(!l1 and !l2)
            return l1;
        if(!l1 and l2)
            return l2;
        if(l1 and !l2)
            return l1;
        reversal(l1);
        reversal(l2);
        struct Node *l3=NULL;
        int c = 0;
        struct Node *p = l1,*q = l2,*r = NULL;
        while(p or q)
        {
            c += p?p->data:0;
            c += q?q->data:0;
            if(l3==NULL)
            {
                l3 = new Node(c%10);
                r = l3;
            }
            else
            {
                r->next = new Node(c%10);
                r = r->next;
            }
                
            c = c>=10?1:0;
            p=p?p->next:NULL;
            q=q?q->next:NULL;
        }
        if(c==1)
        {
            r->next = new Node(1);
        }
        reversal(l3);
        
        return l3;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
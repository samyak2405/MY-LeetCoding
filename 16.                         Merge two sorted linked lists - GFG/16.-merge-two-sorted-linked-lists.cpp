// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(!head1 and !head2)
        return NULL;
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    Node *p = head1;
    Node *q = head2;
    Node *head = new Node(0);
    Node *tail = head;
    while(p and q)
    {
        if(p->data<q->data)
        {
            Node *newnode = new Node(p->data);
            tail->next = newnode;
            tail = newnode;
            p =p->next;
        }
        else
        {
            Node *newnode = new Node(q->data);
            tail->next = newnode;
            tail = newnode;
            q = q->next;
        }
    }
    while(p)
    {
        Node *newnode = new Node(p->data);
        tail->next = newnode;
        tail = newnode;
        p = p->next;
    }
    while(q)
    {
        Node *newnode = new Node(q->data);
        tail->next = newnode;
        tail = newnode;
        q = q->next;
    }
    return head->next;
        
}  
// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

Node* subLinkedList(Node* l1, Node* l2);

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
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* Structure of linked list Node

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

//You are required to complete this method

int getLength(Node *head)
{
    int res = 0;
    
    while(head)
    {
        res++;
        head = head->next;
    }
    
    return res;
}

Node *reversal(Node *head)
{
    Node *prev = NULL,*forward = NULL,*curr = head;
    
    while(curr)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    
    return prev;
}

Node* subLinkedList(Node* l1, Node* l2)
{
    while(l1 and l1->data==0)
        l1 = l1->next;
    while(l2 and l2->data==0)
        l2 = l2->next;
    
    int n1 = getLength(l1);
    int n2 = getLength(l2);
    
    if(n2>n1)
        swap(l1,l2);
    if(n1==n2)
    {
        Node *t1 = l1,*t2 = l2;
        while(t1->data==t2->data)
        {
            t1 = t1->next;
            t2 = t2->next;
            if(!t1)
                return new Node(0);
        }
        if(t2->data>t1->data)
            swap(l1,l2);
    }
    l1 = reversal(l1);
    l2 = reversal(l2);
    
    Node *res = NULL;
    Node *t1 = l1,*t2 = l2;
    while(t1)
    {
        int small = 0;
        if(t2)
            small = t2->data;
        if(small>t1->data)
        {
            t1->next->data -=1;
            t1->data +=10;
        }
        Node *n = new Node(t1->data-small);
        n->next = res;
        res = n;
        
        t1 = t1->next;
        if(t2)
            t2 = t2->next;
    }
    while(res and res->data==0)
        res = res->next;
    return res;
}

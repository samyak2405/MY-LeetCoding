// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}
// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function

void reverse(Node *&head)
{
    Node *prev = NULL,*curr = head,*forward = NULL;
    while(curr)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

Node *merge(Node *head1,Node *head2)
{
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    Node *temp = NULL;
    
    if(head1->data<head2->data)
    {
        temp = head1;
        head1->next = merge(head1->next,head2);
    }
    else
    {
        temp = head2;
        head2->next = merge(head1,head2->next);
    }
    
    return temp;
}

void split(Node *head,Node **ahead,Node **dhead)
{
    *ahead = new Node(0);
    *dhead = new Node(0);
    Node *asec = *ahead;
    Node *dsec = *dhead;
    Node *curr = head;
    while(curr)
    {
        asec->next = curr;
        asec = asec->next;
        curr = curr->next;
        if(curr)
        {
            dsec->next = curr;
            dsec = dsec->next;
            curr = curr->next;
        }
    }
    asec->next = NULL;
    dsec->next = NULL;
    *ahead = (*ahead)->next;
    *dhead = (*dhead)->next;
}

void sort(Node **head)
{
    Node *ahead,*dhead;
    split(*head,&ahead,&dhead);
     reverse(dhead);
     *head = merge(ahead,dhead);
}
// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

 // } Driver Code Ends
//User function Template for C++

/* Linked List node structure
    
struct Node {
	int data;
	struct Node *next;
};

*/

class Solution
{
    public:
    Node* removeAllDuplicates(struct Node* head)
    {
        if(!head or !head->next)
        return head;
    Node *dummpy = new Node(-1);
    dummpy->next = head;
    Node *prev = dummpy;
    Node *p = head;
    Node *q = head->next;
    while(q)
    {
        if(p->data==q->data)
        {
            while(q and p->data==q->data)
                q = q->next;
            prev->next = q;
            p = q;
            if(q)
                q = q->next;
        }
        else
        {
            prev = p;
            p = p->next;
            q = q->next;
        }
    }
    return dummpy->next;
    }
};

// { Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;


	while (T--)
	{
		int N;

		cin >> N ;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		Solution ob;
		head = ob.removeAllDuplicates(head);
		printList(head);

		cout << "\n";


	}
	return 0;
}
  // } Driver Code Ends
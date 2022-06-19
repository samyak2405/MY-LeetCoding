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

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    
    Node *reverseLL(Node *head)
    {
        Node *curr = head,*prev = NULL,*forward = NULL;
        while(curr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    Node* reverseBetween(Node* head, int m, int n)
    {
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *p = dummy,*q = dummy;
        m--;
        n++;
        while(p and m--)
            p = p->next;
        while(q and n--)
            q = q->next;
        Node *r = p->next;
        Node *s = r;
        while(s->next!=q)
            s=s->next;
        s->next = NULL;
        r = reverseLL(r);
        p->next = r;
        while(p->next)
            p = p->next;
        p->next = q;
        return dummy->next;
        // vector<int> v1;
        // Node *p = head;
        // while(p)
        // {
        //     v1.push_back(p->data);
        //     p=p->next;
        // }
        // reverse(v1.begin()+m-1,v1.begin()+n);
        // Node *dummy = new Node(0);
        // p = dummy;
        // for(int i = 0;i<v1.size();i++)
        // {
        //     Node *newnode = new Node(v1[i]);
        //     p->next = newnode;
        //     p = p->next;
        // }
        // return dummy->next;
        
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
		int N, m, n;
		cin >> N>>m>>n;

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

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends
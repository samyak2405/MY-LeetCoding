// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    if(!head or !head->next)
        return head;
    vector<int> res;
    Node *p = head;
    while(p)
    {
        res.emplace_back(p->data);
        p = p->next;
    }
    Node *head1 = NULL,*tail1 = NULL;
    
    for(int i = 0;i<res.size();i++)
    {
        if(res[i]<x)
        {
            Node *newnode = new Node(res[i]);
            if(!head1)
            {
                head1 = newnode;
                tail1 = newnode;
            }
            else
            {
                tail1->next = newnode;
                tail1 = newnode;
            }
        }
    }
    for(int i = 0;i<res.size();i++)
    {
        if(res[i]==x)
        {
            Node *newnode = new Node(res[i]);
            if(!head1)
            {
                head1 = newnode;
                tail1 = newnode;
            }
            else
            {
                tail1->next = newnode;
                tail1 = newnode;
            }
        }
    }
    
    for(int i = 0;i<res.size();i++)
    {
        if(res[i]>x)
        {
            Node *newnode = new Node(res[i]);
            if(!head1)
            {
                head1 = newnode;
                tail1 = newnode;
            }
            else
            {
                tail1->next = newnode;
                tail1 = newnode;
            }
        }
    }
    
    return head1;
}
// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


Node *swapkthnode(Node* head, int n, int k)
{
    if(k>n)
        return head;
    Node *first = head,*second = head,*fprev = NULL,*sprev = NULL,*temp;
    
    for(int i = 0;i<k-1;i++)
    {
        fprev = first;
        first = first->next;
    }
    for(int i = 0;i<n-k;i++)
    {
        sprev = second;
        second = second->next;
    }
    
    if(k==1)
    {
        sprev->next = first;
        second->next = first->next;
        first->next = NULL;
        return second;
    }
    if(k==n)
    {
        fprev->next = second;
        first->next = second->next;
        second->next = NULL;
        return first;
    }
    else
    {
        fprev->next = second;
        sprev->next = first;
        temp = first->next;
        first->next = second->next;
        second->next = temp;
    }
    return head;
}

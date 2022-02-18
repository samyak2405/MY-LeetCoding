/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *p = head;
        Node *q = head;
        while(p)
        {
            q = p->next;
            Node *newnode = new Node(p->val);
            newnode->next = q;
            p->next = newnode;
            p = q;
        }
        p = head;
        while(p)
        {
            if(p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        p = head;
        Node *head1 = new Node(0);
        Node *tail1 = head1;
        
        while(p)
        {
            q = p->next->next;
            tail1->next = p->next;
            p->next = q;
            tail1 = tail1->next;
            p = q;
        }
        return head1->next;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return NULL;
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *previous = dummy;
        stack<Node *> s1;
        s1.push(head);
        while(!s1.empty())
        {
            Node *node = s1.top();
            s1.pop();
            if(node->next)
                s1.push(node->next);
            if(node->child)
                s1.push(node->child);
            if(!s1.empty())
                node->next = s1.top();
            else
                node->next = NULL;
            node->child = NULL;
            node->prev = previous;
            previous = node;
        }
        head->prev = NULL;
        dummy->next = NULL;
        return head;
    }
};
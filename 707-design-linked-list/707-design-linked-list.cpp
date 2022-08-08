class Node{
    public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};


class MyLinkedList {
    Node *head;
    int size;
public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index>=size or index<0)
            return -1;
        Node *curr = head;
        for(int i = 0;i<index;i++)
            curr = curr->next;
        return curr->data;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index>size or index<0)
            return;
        Node *curr = head;
        Node *newnode = new Node(val);
        if(index==0)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            for(int i = 0;i<index-1;i++)
                curr = curr->next;
            Node *temp = curr->next;
            curr->next = newnode;
            newnode->next = temp;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size or index<0)
            return;
        if(index==0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            
            Node *curr = head;
            for(int i = 0;i<index-1;i++)
                curr = curr->next;
            Node* nextNode = curr->next->next;
            delete curr->next;
            curr->next = nextNode;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
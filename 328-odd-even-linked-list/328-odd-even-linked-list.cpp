/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    void insert(ListNode *&head,ListNode *&tail,vector<int> &v1,int start)
    {
        for(int i = start;i<v1.size();i+=2)
        {
            ListNode *newnode = new ListNode(v1[i]);
            if(!head)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                tail->next = newnode;
                tail = newnode;
            }
        }
    }
    
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode *p = head;
        vector<int> v1;
        while(p)
        {
            v1.push_back(p->val);
            p = p->next;
        }
        ListNode *head1 = NULL,*tail1 = NULL;
        
        insert(head1,tail1,v1,0);
        insert(head1,tail1,v1,1);
        
        return head1;
    }
};
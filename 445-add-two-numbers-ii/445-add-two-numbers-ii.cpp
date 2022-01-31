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
    
    void reversal(ListNode *&head)
    {
        ListNode *prev = NULL,*curr = head,*forward = NULL;
        
        while(curr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = forward;
        }
        
        head = prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 and !l2)
            return l1;
        if(!l1 and l2)
            return l2;
        if(l1 and !l2)
            return l1;
        reversal(l1);
        reversal(l2);
        ListNode *l3=NULL;
        int c = 0;
        ListNode *p = l1,*q = l2,*r = NULL;
        while(p or q)
        {
            c += p?p->val:0;
            c += q?q->val:0;
            if(l3==NULL)
            {
                l3 = new ListNode(c%10);
                r = l3;
            }
            else
            {
                r->next = new ListNode(c%10);
                r = r->next;
            }
                
            c = c>=10?1:0;
            p=p?p->next:NULL;
            q=q?q->next:NULL;
        }
        if(c==1)
        {
            r->next = new ListNode(1);
        }
        reversal(l3);
        
        return l3;
    }
};
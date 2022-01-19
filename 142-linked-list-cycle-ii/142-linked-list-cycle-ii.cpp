/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return head;
        if(!head->next)
            return NULL;
        ListNode *p = head,*q = head;
        while(p and q and q->next)
        {
            p = p->next;
            q = q->next->next;
            if(p==q)
            {
                p = head;
                while(p!=q)
                {
                    p=p->next;
                    q = q->next;
                }
                if(p==q)
                    return p;
            }
        }
        return NULL;
    }
};
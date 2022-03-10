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
            return NULL;
        ListNode *p = head;
        ListNode *q = head;
        while(p and q and q->next)
        {
            p = p->next;
            q = q->next->next;
            if(p==q)
            {
                p = head;
                while(p!=q)
                {

                    p = p->next;
                    q = q->next;
                }
                return p;
            }
        }
        return NULL;
    }
};
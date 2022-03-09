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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode *dummpy = new ListNode(-1);
        dummpy->next = head;
        ListNode *prev = dummpy;
        ListNode *p = head;
        ListNode *q = head->next;
        while(q)
        {
            if(p->val==q->val)
            {
                while(q and p->val==q->val)
                    q = q->next;
                prev->next = q;
                p = q;
                if(q)
                    q = q->next;
            }
            else
            {
                prev = p;
                p = p->next;
                q = q->next;
            }
        }
        return dummpy->next;
    }
};
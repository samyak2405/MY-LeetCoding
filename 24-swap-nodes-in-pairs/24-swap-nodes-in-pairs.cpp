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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode *dum = new ListNode(0);
        dum->next = head;
        ListNode *prev = dum,*p = head,*q = head->next;
        while(p and q)
        {
            p->next = q->next;
            q->next = p;
            prev->next = q;
            prev = p;
            p = p->next?p->next:NULL;
            q = p?p->next:NULL;
        }
        return dum->next;
    }
};
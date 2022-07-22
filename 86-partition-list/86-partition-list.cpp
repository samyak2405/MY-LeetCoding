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
    ListNode* partition(ListNode* head, int x) {
        if(!head or !head->next)
            return head;
        ListNode *p = head,*q = p;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        while(p)
        {
            if(p->val>=x)
            {
                q = p;
                p = p->next;
            }
            else if(p->val<x and pre->next == p)
            {
                q = p;
                p = p->next;
                pre = pre->next;
            }
            else if(p->val<x)
            {
                ListNode *temp = pre->next;
                pre->next = p;
                pre = pre->next;
                q->next = p->next;
                p->next = temp;
                p = q->next;
            }
        }
        return dummy->next;
    }
};
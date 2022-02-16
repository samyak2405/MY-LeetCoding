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
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)
            return true;
        ListNode *p = head;
        ListNode *q = head;
        ListNode *r;
        while(q and q->next)
        {
            r = p;
            p = p->next;
            q = q->next->next;
        }
        q = r;
        q->next = NULL;
        ListNode *prev = NULL,*forward = NULL,*curr = p;
        while(curr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        p = prev;
        q = head;
        while(p and q)
        {
            if(p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }
        
        return true;
    }
};
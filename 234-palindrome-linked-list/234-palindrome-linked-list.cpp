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
        while(q and q->next)
        {
            p = p->next;
            q = q->next->next;
        }
        q = head;
        while(q->next!=p)
            q = q->next;
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
        while(prev)
        {
            cout<<prev->val<<" ";
            prev = prev->next;
        }
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
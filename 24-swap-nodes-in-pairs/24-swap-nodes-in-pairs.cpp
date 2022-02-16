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
        
        ListNode *p = head,*q = head->next;
        
        while(p and q)
        {
            swap(p->val,q->val);
            p = p->next?p->next->next:NULL;
            q = q->next?q->next->next:NULL;
        }
        
        return head;
    }
};
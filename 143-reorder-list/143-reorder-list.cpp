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
    
    ListNode *rev(ListNode *head)
    {
        ListNode *current = head;
        ListNode *previous = NULL,*forward = NULL;
        while(current)
        {
            forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
        }
        return previous;
    }
    
    void reorderList(ListNode* head) {
        if(!head or !head->next)
            return;
        
        ListNode *slow = head,*fast = head;
        ListNode *p = slow;
        while(fast and fast->next)
        {
            p = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        p->next = NULL;
        slow = rev(slow);
        p = head;
        ListNode *prev = slow;
        while(p and slow)
        {
            prev = slow;
            ListNode *tmp1 = p->next;
            ListNode *tmp2 = slow->next;
            p->next = slow;
            slow->next = tmp1;
            p = slow->next;
            slow = tmp2;
        }
        while(slow)
        {
            prev->next = slow;
            slow = slow->next;
            prev = prev->next;
        }
        
    }
};
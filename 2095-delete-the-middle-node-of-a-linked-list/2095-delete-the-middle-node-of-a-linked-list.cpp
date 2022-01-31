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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head)
            return head;
        if(!head->next)
            return NULL;
        int n = 0;
        ListNode *p = head;
        
        while(p)
        {
            n++;
            p=p->next;
        }
        
        n = (n/2)-1;
        p = head;
        while(n--)
            p=p->next;
        
        ListNode *tmp = p->next;
        p->next = tmp->next;
        
        delete tmp;
        
        return head;
    }
};
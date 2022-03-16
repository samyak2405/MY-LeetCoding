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
    ListNode* insertionSortList(ListNode* head) {
        
        if(!head or !head->next)
            return head;
        
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *curr = head,*prev = start;
        
        while(curr)
        {
            if(curr->next and (curr->next->val < curr->val))
            {
                while(prev->next and (prev->next->val < curr->next->val))
                    prev = prev->next;
                
                ListNode *temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                 prev->next->next = temp;
                prev = start;
            }
            else
            {
                curr = curr->next;
            }
        }
        head = start->next;
        
        delete start;
        return head;
    }
};
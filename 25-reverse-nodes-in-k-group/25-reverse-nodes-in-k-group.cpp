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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or k==1)
            return head;
        int num = 0;
        
        ListNode *dum = new ListNode(0);
        dum->next = head;
        ListNode *forward = dum,*prev = dum,*curr = dum;
        while(curr = curr->next)
            num++;
        while(num>=k)
        {
            curr = prev->next;
            forward = curr->next;
            for(int i =1;i<k;i++)
            {
                curr->next = forward->next;
                forward->next = prev->next;
                prev->next = forward;
                forward = curr->next;
            }
            
            prev = curr;
            num-=k;
        }
        return dum->next;
    }
};
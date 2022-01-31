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
    int pairSum(ListNode* head) {
        ListNode *fast = head,*slow = head;
        
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *nextnode ,*prev = NULL;
        
        while(slow)
        {
            nextnode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextnode;
        }
        
        int maxi = INT_MIN;
        
        while(prev)
        {
            maxi = max(maxi,head->val+prev->val);
            head = head->next;
            prev = prev->next;
        }
        
        return maxi;
    }
};
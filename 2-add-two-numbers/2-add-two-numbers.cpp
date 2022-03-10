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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        int sum = 0,carry = 0;
        
        while(l1 or l2)
        {
            sum = carry + (l1?l1->val:0) + (l2?l2->val:0);
            carry = (sum>=10)?1:0;
            int digit = sum%10;
            ListNode *newnode = new ListNode(digit);
            if(!head)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                tail->next = newnode;
                tail = newnode;
            }
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        if(carry)
        {
            ListNode *newnode = new ListNode(carry);
            tail->next = newnode;
        }
        
        return head;
    }
};
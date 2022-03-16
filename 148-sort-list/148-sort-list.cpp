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
    ListNode* sortList(ListNode* head) {
        ListNode *newnode = new ListNode(0);
        newnode->next = head;
        ListNode *prev = newnode,*curr = head;
        while(curr)
        {
            if(curr->next and (curr->next->val<curr->val))
            {
                while(prev->next and (prev->next->val<curr->next->val))
                    prev = prev->next;
                ListNode *temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
                prev = newnode;
            }
            else
                curr = curr->next;
        }
        return newnode->next;
    }
};
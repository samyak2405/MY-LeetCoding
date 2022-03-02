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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or !head->next)
            return head;
        ListNode *p = head;
        vector<int> v1;
        while(p)
        {
            v1.push_back(p->val);
            p = p->next;
        }
        
        left--;
        // right--;
        reverse(v1.begin()+left,v1.begin()+right);
        ListNode *head1 = NULL;
        ListNode *tail1 = NULL;
        for(auto it:v1)
        {
            ListNode *node = new ListNode(it);
            if(!head1)
            {
                head1 = node;
                tail1 = node;
            }
            else
            {
                tail1->next = node;
                tail1 = node;
            }
        }
        return head1;
    }
};
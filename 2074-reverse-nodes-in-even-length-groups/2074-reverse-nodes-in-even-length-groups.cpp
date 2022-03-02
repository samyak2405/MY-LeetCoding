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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(!head or !head->next)
            return head;
        vector<int> v1;
        ListNode *p = head;
        int i = 1;
        while(p)
        {
            vector<int> tmp;
            int t = i++;
            while(t-- and p)
            {
                tmp.push_back(p->val);
                p = p->next;
            }
            if(tmp.size()%2==0)
                reverse(tmp.begin(),tmp.end());
            for(auto it:tmp)
            {
                v1.push_back(it);
            }
        }
        
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
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or !k)
            return head;
        ListNode *p = head;
        int n = 1;
        while(p->next)
        {
            p = p->next;
            n++;
        }
        p->next = head;
        k%=n;
        n = n-k;
        while(n--)
            p = p->next;
        head = p->next;
        p->next = NULL;
        return head;
    }
};
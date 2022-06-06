/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0;
        int n2 = 0;
        ListNode *p = headA,*q = headB;
        while(p)
        {
            n1++;
            p=p->next;
        }
        while(q)
        {
            n2++;
            q = q->next;
        }
        int tmp = 0;
        p = headA;
        q = headB;
        if(n1>n2)
        {
            tmp = n1-n2;
            while(tmp--)
                p = p->next;
        }
        else
        {
            tmp = n2-n1;
            while(tmp--)
                q = q->next;
        }
        while(p!=q)
        {
            p =p ->next;
            q = q->next;
        }
        return p;
    }
};
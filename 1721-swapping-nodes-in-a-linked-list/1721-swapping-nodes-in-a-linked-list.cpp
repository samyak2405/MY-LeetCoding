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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode *p = head;
        while(p)
        {
            n++;
            p = p->next;
        }
        if(n==0 or n==1 or k>n)
            return head;
            
        ListNode *first = head,*second = head,*fprev = NULL,*sprev = NULL,*temp;
        
        for(int i = 0;i<k-1;i++)
        {
            fprev = first;
            first = first->next;
        }
        for(int i = 0;i<n-k;i++)
        {
            sprev = second;
            second = second->next;
        }
        if(k==1)
        {
            sprev->next = first;
            second->next = first->next;
            first->next = NULL;
            return second;
        }
        if(k==n)
        {
            fprev->next = second;
            first->next = second->next;
            second->next = NULL;
            return first;
        }
        else
        {
            fprev->next = second;
            sprev->next = first;
            temp = first->next;
            first->next = second->next;
            second->next = temp;
        }
        return head;
    }
};
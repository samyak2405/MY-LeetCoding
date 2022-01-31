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
        
        ListNode* p = head;
        int n = 0;
        
        while(p)
        {
            p=p->next;
            n++;
        }
        
        p = head;
        int i = 0,t = n/2;
        vector<int> res(n/2,0);
        while(t--)
        {
            res[i] = p->val;
            p=p->next;
            i++;
        }
        i = 0;
        
        while(p)
        {
            res[res.size()-1-i]+=p->val;
            p=p->next;
            i++;
        }
        int maxi = INT_MIN;
        for(int i =0;i<res.size();i++)
            maxi = max(maxi,res[i]);
        
        return maxi;
    }
};
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        if(lists.size()==0)
            return NULL;
        for(auto it:lists)
        {
            ListNode *p = it;
            while(p)
            {
                pq.push(p->val);
                p=p->next;
            }
        }
        ListNode *head = NULL,*tail = NULL;
        
        while(!pq.empty())
        {
            ListNode *newnode = new ListNode(pq.top());
            pq.pop();
            if(!head)
            {
                head=newnode;
                tail=newnode;
            }
            else
            {
                tail->next = newnode;
                tail=newnode;
            }
        }
        return head;
        
    }
};
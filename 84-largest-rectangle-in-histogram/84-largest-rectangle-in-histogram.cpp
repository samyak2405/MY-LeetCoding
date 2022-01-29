class Solution {
public:
    int largestRectangleArea(vector<int>& v1) {
        stack<int> s1;
        int res = 0;
        int n = v1.size();
        int curr;
        for(int i =0;i<n;i++)
        {
            while(!s1.empty() and v1[s1.top()]>=v1[i])
            {
                int tp = s1.top();
                s1.pop();
                curr = v1[tp]*(s1.empty()?i:i-s1.top()-1);
                res = max(res,curr);
            }
            s1.push(i);
        }
        while(!s1.empty())
        {
            int tp = s1.top();
            s1.pop();
            curr = v1[tp]*(s1.empty()?n:n-s1.top()-1);
            res = max(res,curr);
        }
        return res;
    }
};
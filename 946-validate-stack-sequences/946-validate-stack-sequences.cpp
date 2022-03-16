class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s1;
        int i = 0,j = 0;
        while(i<pushed.size() and j<popped.size())
        {
            if(s1.empty() or s1.top()!=popped[j])
            {
                s1.push(pushed[i]);
                i++;
            }
            else
            {
                while(!s1.empty() and s1.top()==popped[j])
                {
                    s1.pop();
                    j++;
                }
            }
        }
        while(!s1.empty() and j<popped.size())
        {
            if(s1.top()!=popped[j])
                return false;
            s1.pop();
            j++;
        }
        return true;
    }
};
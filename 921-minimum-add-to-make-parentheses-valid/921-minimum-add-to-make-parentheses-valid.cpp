class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int cnt = 0;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]=='(')
                stk.push(s[i]);
            else
            {
                if(stk.empty())
                    cnt++;
                else
                    stk.pop();
            }
        }
        cnt+=stk.size();
        return cnt;
    }
};
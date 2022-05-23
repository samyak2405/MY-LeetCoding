class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> indstk;
        stack<char> chstk;
        indstk.push(-1);
        int len = 0;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                chstk.push('(');
                indstk.push(i);
            }
            else if(s[i]==')')
            {
                if(chstk.empty())
                {
                    indstk.push(i);
                }
                else
                {
                    chstk.pop();
                    indstk.pop();
                    len = max(len,i-indstk.top());
                }
            }
        }
        
        return len;
    }
};
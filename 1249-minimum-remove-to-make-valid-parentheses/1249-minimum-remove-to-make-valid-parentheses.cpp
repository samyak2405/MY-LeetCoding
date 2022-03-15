class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res="";
        stack<int> s1;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]!='(' and s[i]!=')')
                continue;
            else if(s[i]==')' and !s1.empty() and s[s1.top()]=='(')
                s1.pop();
            else
                s1.push(i);
        }
        while(!s1.empty())
        {
            s[s1.top()] = '.';
            s1.pop();
        }
        for(auto it:s)
        {
            if(it=='.')
                continue;
            else
                res+=it;
        }
        return res;
    }
};
class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res="";
        int len = s.length();
        stack<pair<char,int>> s1;

        for(int i = 0;i<len;i++)
        {
            if(s1.empty())
                s1.push({s[i],1});
            else
            {
                if(s1.top().first==s[i])
                {
                    s1.top().second++;
                    if(s1.top().second==k)
                        s1.pop();
                }
                else
                    s1.push({s[i],1});
            }
        }
        
        while(!s1.empty())
        {
            while(s1.top().second--)
                res+=s1.top().first;
            s1.pop();
        }
        reverse(res.begin(),res.end());
        // if(res==s)
        //     return res;
        // return removeDuplicates(res,k);
        return res;
    }
};
class Solution {
public:
    
    bool f(string s1,string s2,int count)
    {
        int s1count[26] = {0};
        int s2count[26] = {0};
        for(int i = 0;i<s1.length();i++)
            s1count[s1[i]-'a']++;
        for(int i = 0;i<s2.length();i++)
            s2count[s2[i]-'a']++;
        int cnt = 0;
        for(int i = 0;i<26;i++)
        {
            if(s2count[i]!=0 and s1count[i]>=s2count[i])
                cnt++;
            else if(s2count[i]!=0 and s1count[i]<s2count[i])
                return false;
        }
        return count==cnt;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words2.size();
        int wordcount[26] = {0};
        for(int i = 0;i<n;i++)
        {
            int tmp[26] = {0};
            for(int j = 0;j<words2[i].size();j++)
                tmp[words2[i][j]-'a']++;
            for(int i = 0;i<26;i++)
                wordcount[i] = max(wordcount[i],tmp[i]);
        }
        string tmp = "";
        int cnt = 0;
        for(int i = 0;i<26;i++)
        {
            if(wordcount[i]>0)
            {
                while(wordcount[i]>0)
                {
                    tmp+=(i+'a');
                    wordcount[i]--;
                }
                cnt++;
            }
            
        }
        vector<string> res;
        cout<<tmp<<" "<<cnt<<endl;
        int m = words1.size();
        for(int i = 0;i<m;i++)
        {
            if(f(words1[i],tmp,cnt))
                res.push_back(words1[i]);
        }
        return res;
    }
};
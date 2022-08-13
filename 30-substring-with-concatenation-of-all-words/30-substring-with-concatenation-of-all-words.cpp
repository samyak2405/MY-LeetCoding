class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.length();
        int num = words.size();
        int len = words[0].length();
        unordered_map<string,int> count;
        for(auto it:words)
            count[it]++;
        for(int i = 0;i<n-num*len+1;i++)
        {
            unordered_map<string,int> seen;
            int j = 0;
            for(;j<num;j++)
            {
                string tmp = s.substr(i+j*len,len);
                if(count.find(tmp)!=count.end())
                {
                    seen[tmp]++;
                    if(seen[tmp]>count[tmp])
                        break;
                }
                else
                    break;
            }
            if(j==num)
                res.push_back(i);
            
        }
        return res;
    }
};
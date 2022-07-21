class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0,j = 0;
        unordered_map<int,int> mp;
        int res = 0;
        int maxCnt = 0;
        int n = s.length();
        while(j<n)
        {
            mp[s[j]]++;
            maxCnt = max(maxCnt,mp[s[j]]);
            while(j-i+1-k>maxCnt)
            {
                mp[s[i]]--;
                i++;
            }
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};
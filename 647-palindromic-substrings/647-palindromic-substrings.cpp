class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.length();
        
        for(int i =0;i<n;i++){
            for(int l = i, r = i;(l>=0) and (r<n) and (s[l]==s[r]);l--,r++ )
                cnt++;
            for(int l = i,r = i+1;(l>=0) and (r<n) and (s[l]==s[r]);l--,r++)
                cnt++;
        }
        
        return cnt;
    }
};
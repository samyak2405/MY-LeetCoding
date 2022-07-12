class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0,max_cnt = 0;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]=='[')
                cnt--;
            else
                cnt++;
            max_cnt = max(cnt,max_cnt);
        }
        return (max_cnt+1)/2;
    }
};
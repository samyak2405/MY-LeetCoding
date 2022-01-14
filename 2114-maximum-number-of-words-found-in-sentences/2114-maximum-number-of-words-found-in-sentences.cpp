class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max_cnt = 0;
        for(auto it:sentences)
        {
            int cnt = count(it.begin(),it.end(),' ');
            max_cnt = max(max_cnt,cnt+1);
        }
        return max_cnt;
    }
};
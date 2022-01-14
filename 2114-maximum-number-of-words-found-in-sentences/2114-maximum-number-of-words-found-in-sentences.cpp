class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int cnt = 0;
        int max_cnt = 0;
        for(int i = 0;i<sentences.size();i++)
        {
            cnt = 0;
            for(int j =0;j<sentences[i].length();j++)
            {
                if(sentences[i][j]==' ')
                    cnt++;
                while(sentences[i][j]==' ')
                    j++;
            }
            max_cnt = max(max_cnt,cnt+1);
        }
        return max_cnt;
    }
};
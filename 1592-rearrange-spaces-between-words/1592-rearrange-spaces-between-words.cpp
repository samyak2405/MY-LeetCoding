class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> res;
        int n = text.length();
        int spaces = 0,word_cnt = 0;
        stringstream ss(text);
        string word;
        string ans;
        while(ss>>word)
        {
            res.push_back(word);
            word_cnt++;
        }
        for(int i = 0;i<n;i++)
            if(text[i]==' ')
                spaces++;
        if(word_cnt==1)
        {
            ans+=res[0];
            while(spaces--)
                ans+=" ";
            return ans;
        }
        int nos_spaces = spaces/(word_cnt-1),extraspaces = spaces%(word_cnt-1);
        for(int i = 0;i<res.size()-1;i++)
        {
            ans+=res[i];
            int cnt = 0;
            while(cnt++<nos_spaces)
                ans+=" ";
        }
        ans+=res[res.size()-1];
        while(extraspaces--)
            ans+=" ";
        return ans;
    }
};
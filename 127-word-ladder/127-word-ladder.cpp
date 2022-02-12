class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s1(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int cnt = 1;
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0;i<n;i++)
            {
                string word = q.front();
                q.pop();
                if(word==endWord)
                    return cnt;
                
                for(int j = 0;j<word.size();j++)
                {
                    int c = word[j];
                    
                    for(int k = 0;k<26;k++)
                    {
                        word[j] = 'a'+ k;
                        if(s1.find(word)!=s1.end())
                        {
                            q.push(word);
                            s1.erase(word);
                        }
                    }
                    
                    word[j] = c;
                }
                
            }
            cnt++;
        }
        return 0;
    }
};
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int cnt[26] = {0};
        
        for(int i = 0;i<letters.size();i++)
        {
            cnt[letters[i]-'a']++;
        }
        
        int i = target-'a'+1;
        while(i<26 and cnt[i]==0)
            i++;
        if(i>=26)
            return letters[0];
        return 'a'+i;
    }
};
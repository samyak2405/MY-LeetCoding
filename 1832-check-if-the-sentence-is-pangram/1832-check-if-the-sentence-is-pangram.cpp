class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> s1;
        for(int i = 0;i<26;i++)
        {
            s1.insert('a'+i);
        }
        for(int i = 0;i<sentence.size();i++)
            if(s1.find(sentence[i])!=s1.end())
                s1.erase(sentence[i]);
        if(s1.size())
            return false;
        return true;
    }
};
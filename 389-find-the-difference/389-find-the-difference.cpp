class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr1[256] = {0},arr2[256] = {0};
        for(auto it:s)
            arr1[it-'a']++;
        for(auto it:t)
            arr2[it-'a']++;
        char ch;
        for(int i = 0;i<256;i++)
            if(arr1[i]!=arr2[i])
            {
                ch = 'a'+i;
            }
        return ch;
    }
};
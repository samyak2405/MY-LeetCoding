class Solution {
public:
    int minSteps(string s, string t) {
        int arr[26] = {0};
        for(auto it:s)
            arr[it-'a']++;
        for(auto it:t)
        {
            arr[it-'a']--;
        }
        int sum = 0;
        for(int i = 0;i<26;i++)
            sum+=abs(arr[i]);
        return sum;
    }
};
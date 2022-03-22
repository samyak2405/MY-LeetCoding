class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int> res(n,1);
        k-=n;
        int i = n-1;
        while(k)
        {
            if(k>=25)
            {
                res[i]+=25;
                i--;
                k-=25;
            }
            else
            {
                res[i]+=k;
                k = 0;
            }
        }
        string result = "";
        for(auto it:res)
            result+=('a'+it-1);
        return result;
    }
};
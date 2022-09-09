class Solution {
public:
    
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int cnt = 0;
        int n = properties.size();
        sort(properties.begin(),properties.end(),cmp);
        int mtn = INT_MIN;
        for(int i = n-1;i>=0;i--)
        {
            if(properties[i][1]<mtn)
                cnt++;
            mtn = max(mtn,properties[i][1]);
        }
        return cnt;
    }
};
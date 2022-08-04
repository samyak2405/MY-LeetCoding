class Solution {
public:
    
    int hist(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left(n,-1),right(n,n);
        stack<pair<int,int>> s1,s2;
        for(int i = 0;i<n;i++)
        {
            while(!s1.empty() and s1.top().first>=arr[i])
                s1.pop();
            if(!s1.empty() and s1.top().first<arr[i])
                left[i] = s1.top().second;
            s1.push({arr[i],i});
        }
        for(int i = n-1;i>=0;i--)
        {
            while(!s2.empty() and s2.top().first>=arr[i])
                s2.pop();
            if(!s2.empty() and s2.top().first<arr[i])
                right[i] = s2.top().second;
            s2.push({arr[i],i});
        }
        int res = 0;
        for(int i = 0;i<n;i++)
            res = max(res,(right[i]-left[i]-1)*arr[i]);
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        vector<int> dp(m,0);
        for(int i = 0;i<n;i++)
        {
            for(int j= 0;j<m;j++)
            {
                if(matrix[i][j] == '0')
                    dp[j] = 0;
                else
                    dp[j]++;
            }
            res = max(res,hist(dp));
        }
        return res;
    }
};
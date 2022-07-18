class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        int n = matrix.size(),m = matrix[0].size();
        for(int i =0;i<min(n,k);i++)
            pq.push({matrix[i][0],i,0});
        int ans = 0;
        for(int i =1;i<=k;i++)
        {
            auto it = pq.top();
            pq.pop();
            ans = it[0];
            int r = it[1];
            int c = it[2];
            if(c+1<m)
                pq.push({matrix[r][c+1],r,c+1});
        }
        return ans;
    }
};
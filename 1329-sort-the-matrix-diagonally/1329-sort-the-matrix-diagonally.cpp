class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int,vector<int>> mp;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                mp[i-j].emplace_back(mat[i][j]);
        for(auto &it:mp)
            sort(it.second.begin(),it.second.end(),greater<int>());
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                mat[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return mat;
    }
};
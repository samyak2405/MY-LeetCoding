class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v1;
        for(int i = 0;i<mat.size();i++){
            int cnt = 0;
            for(int j = 0;j<mat[i].size();j++){
                if(mat[i][j]==0)
                    break;
                cnt++;
            }
            v1.push_back({cnt,i});
        }
        sort(v1.begin(),v1.end());
        vector<int> res;
        int i = 0;
        while(k--){
            res.push_back(v1[i].second);
            i++;
        }
        return res;
    }
};
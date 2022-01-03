class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cnt(n+1,0);
        for(auto it:trust)
            cnt[it[0]]--,cnt[it[1]]++;
        for(int i=1;i<=n;i++){
            if(cnt[i]==n-1) return i;
        }
        return -1;
    }
};
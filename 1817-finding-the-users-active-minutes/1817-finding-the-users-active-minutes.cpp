class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k);
        unordered_map<int,unordered_set<int>> mp;
        for(int i = 0;i<logs.size();i++)
            mp[logs[i][0]].insert(logs[i][1]);
        for(auto it:mp)
            res[it.second.size()-1]++;
        return res;
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<pair<int,int>> s1;
        
        for(int i = 0;i<temperatures.size();i++)
        {
            while(!s1.empty() and s1.top().first<temperatures[i])
            {
                res[s1.top().second] = i-s1.top().second;
                s1.pop();
            }
            s1.push({temperatures[i],i});
        }
        return res;
    }
};
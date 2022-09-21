#pragma GCC optimize("O2")
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
                
        int sum = accumulate(nums.begin(), nums.end(), 0, [](int &x, int &y){
            return (y & 1) ? x : x + y;
        });
        int tmp, t0, t1, k, n = queries.size(), i = 0;
        vector<int> ans(n);
        
        for(vector<int> &v : queries){
            t0 = v[0];
            t1 = v[1];
            k = nums[t1];
            tmp = k + t0;
            ans[i++] = sum += (k & 1) ? ((tmp & 1) ? 0 : tmp) : ((tmp & 1) ? -k : t0);
            nums[t1] = tmp;
        }
        return ans;
    }
};
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class Solution {
public:
    typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
    vector<int> countSmaller(vector<int>& nums) {
        pbds a;
        vector<int> res;
        int n = nums.size();
        for(int i = n-1;i>=0;i--)
        {
            a.insert(nums[i]);
            res.push_back(a.order_of_key(nums[i]));
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
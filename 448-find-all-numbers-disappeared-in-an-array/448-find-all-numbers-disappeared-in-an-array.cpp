class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int arr[n+1] ;
        memset(arr,0,sizeof(arr));
        for(int i = 0;i<n;i++)
            arr[nums[i]]++;
        vector<int> ans;
        for(int i = 1;i<=n;i++)
            if(arr[i]==0)
                ans.push_back(i);
        return ans;
    }
};
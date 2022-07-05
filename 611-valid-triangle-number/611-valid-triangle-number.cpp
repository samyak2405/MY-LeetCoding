class Solution {
public:
    
//     bool isValid(int a,int b,int c)
//     {
//         return (a+b>c) and (a+c>b) and (b+c>a);
//     }
    
//     int bSearch(vector<int> &nums,int sum,int low,int high)
//     {
//         while(low<=high and high<nums.size())
//         {
//             int mid = low+(high-low)/2;
//             if(sum>nums[mid])
//                 low = mid+1;
//             else
//                 high = mid-1;
//         }
//         return low;
//     }
    
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt= 0;
        sort(nums.begin(),nums.end());
//         for(int i = 0;i<n-2;i++)
//         {
//             // int k = i+2;
//             // for(int j = i+1;j<n-1 and nums[i]!=0;j++)
//             // {
//             //     // int sum = nums[i]+nums[j];
//             //     // k = bSearch(nums,sum,k,n-1);
//             //     // cnt += abs(k-j-1);
//             //     while(k<n and nums[i]+nums[j]>nums[k])
//             //     {
//             //         k++;
//             //         cnt+=abs(k-j-1);
//             //     }
//             // }
            
        // }
        for(int i = n-1;i>=2;i--)
        {
            int j = 0,k = i-1;
            while(j<k)
            {
                if(nums[j]+nums[k]>nums[i])
                {
                    cnt += k-j;
                    k--;
                }
                else
                    j++;
            }
        }
        return cnt;
    }
};
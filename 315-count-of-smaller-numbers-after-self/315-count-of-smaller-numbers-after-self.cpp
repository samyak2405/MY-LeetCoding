class Solution {
public:
    #define iterator vector<pair<int,int>>::iterator
    
    void sort_count(iterator l,iterator r,vector<int> &count)
    {
        if(r-l<=1)
            return;
        iterator mid = l+(r-l)/2;
        sort_count(l,mid,count);
        sort_count(mid,r,count);
        for(iterator i=l,j =mid;i<mid;i++)
        {
            while(j<r and (*i).first>(*j).first)
                j++;
            count[(*i).second] += j- mid;
        }
        inplace_merge(l,mid,r);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        for(int i = 0;i<n;i++)
            arr.push_back({nums[i],i});
        vector<int> count(n);
        sort_count(arr.begin(),arr.end(),count);
        return count;
    }
};
class Solution {
public:
    #define vpi vector<pair<int,int>>
    #define iterator vector<pair<int,int>>::iterator
    
    int sort_count(iterator l,iterator r)
    {
        if(r-l<=1)
            return 0;
        int count = 0;
        iterator m = l+(r-l)/2;
        count+=sort_count(l,m);
        count+=sort_count(m,r);
        
        for(iterator i = l,j =m;i<m;i++)
        {
            while(j<r and i->first>2L*j->first)
                j++;
            count+=j-m;
        }
        inplace_merge(l,m,r);
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vpi hold;
        for(int i= 0;i<n;i++)
            hold.push_back({nums[i],i});
        return sort_count(hold.begin(),hold.end());
    }
};
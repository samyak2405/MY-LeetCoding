class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s1;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]%2==1)
                s1.insert(nums[i]*2);
            else
                s1.insert(nums[i]);
        }
        int minim = INT_MAX;
        while(1)
        {
            int maxVal = *s1.rbegin();
            int minVal = *s1.begin();
            minim = min(minim,maxVal-minVal);
            s1.erase(maxVal);
            s1.insert(maxVal/2);
            if(*s1.rbegin()%2==1)
                break;
        }
        minim = min(minim,*s1.rbegin()-*s1.begin());
        return minim;
    }
};
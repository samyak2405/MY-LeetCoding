class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum = 0;
        for(auto it:chalk)
            sum+=it;
        int rem = k%sum;
        if(rem==0)
            return 0;
        int i = 0;
        while(rem>=chalk[i])
        {
            rem-=chalk[i];
            i++;
        }
        return i;
    }
};
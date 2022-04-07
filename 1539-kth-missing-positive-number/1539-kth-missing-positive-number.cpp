class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s1;
        for(auto it:arr)
            s1.insert(it);
        int j = 1;
        while(k)
        {
            if(s1.find(j)==s1.end())
                k--;
            j++;
        }
        return j-1;
    }
};
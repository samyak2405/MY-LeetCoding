class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxim = 0;
        int cnt = 0;
        for(int i = 0;i<arr.size();i++)
        {
            if(maxim<arr[i])
            {
                maxim = arr[i];
            }
            if(maxim == i)
                cnt++;
        }
        return cnt;
    }
};
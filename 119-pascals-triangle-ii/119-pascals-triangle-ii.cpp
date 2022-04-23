class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int> prev;
        vector<int> curr;
        for(int i = 0;i<numRows+1;i++)
        {
            curr.resize(i+1);
            curr[0] = curr[i] = 1;
            for(int j = 1;j<i;j++)
                curr[j] = prev[j-1] + prev[j];
            prev = curr;
        }
        return prev;
    }
};
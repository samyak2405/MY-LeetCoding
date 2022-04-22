class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = values[0];
        int score = 0;
        for(int i = 1;i<values.size();i++)
        {
            score = max(score,maxi+values[i]-i);
            maxi = max(maxi,values[i]+i);
        }
        return score;
    }
};
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        int i = 0;
        int cnt = 1;
        while(candies>0)
        {
            if(cnt<=candies)
                res[i%num_people] += cnt;
            else
                res[i%num_people] += candies;
            i++;
            candies-=cnt;
            cnt++;
        }
        return res;
    }
};
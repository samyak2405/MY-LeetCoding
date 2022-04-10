class Solution {
public:
    int calPoints(vector<string>& ops) {
        int score = 0;
        vector<int> res;
        for(auto it:ops)
        {
            if(it=="C")
                res.pop_back();
            else if(it=="D")
                res.push_back(res.back()*2);
            else if(it=="+")
                res.push_back(res[res.size()-1]+res[res.size()-2]);
            else
                res.push_back(stoi(it));
        }
        for(auto it:res)
            score+=it;
        return score;
    }
};
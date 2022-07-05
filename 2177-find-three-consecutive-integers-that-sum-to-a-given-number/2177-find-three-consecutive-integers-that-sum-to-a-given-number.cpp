class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long tmp = num;
        if(tmp%3)
            return {};
        vector<long long> res;
        res.push_back((tmp/3)-1);
        res.push_back(tmp/3);
        res.push_back((tmp/3)+1);
        return res;
    }
};
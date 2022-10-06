class TimeMap {
    map<string,vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &nums = mp[key];
        int low = -1,high = nums.size();
        while(high-low>1)
        {
            int mid = (high+low)/2;
            if(nums[mid].first<=timestamp) low = mid;
            else
                high = mid;
        }
        return low==-1?"":mp[key][low].second;
    }
};

class MyCalendar {
    vector<pair<int,int>> v1;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it:v1)
        {
            if(max(it.first,start)<min(end,it.second))
                return false;
        }
        v1.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
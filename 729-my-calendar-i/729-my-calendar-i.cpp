class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next=mp.lower_bound(start);
        if(next!=mp.end() && next->first < end) return false;
        if(next!=mp.begin() && ((--next)->second>start)) return false;
        mp[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
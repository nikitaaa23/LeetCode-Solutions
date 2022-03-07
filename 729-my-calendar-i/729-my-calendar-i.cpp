class MyCalendar {
public:
    vector<pair<int, int>>cal;
    MyCalendar() {
        //cal = new vector();
    }
    
    bool book(int start, int end) {
        for(auto i : cal){
            if(i.first< end && start < i.second)
                return false;
        }
        cal.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
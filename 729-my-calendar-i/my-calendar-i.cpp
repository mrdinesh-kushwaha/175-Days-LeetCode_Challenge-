class MyCalendar {
public:
    unordered_map<int, int> mp;
    MyCalendar() {
        // no need to do anything
    }
    
    bool book(int x, int y) {
        for(auto& val : mp) {
            int a = val.first, b = val.second;

            // Condition 1: If new interval [x, y) overlaps at the end of an existing interval [a, b)
            if(a < y && b > x) {
                return false;
            }

            // Condition 3: If new interval [x, y) is completely within an existing interval [a, b)
            if(a <= x && y <= b) {
                return false;
            }

            // Condition 4
            if(x<a && b<y){
                return false;
            }

        }

        // If no overlap is found, book the interval
        mp[x] = y;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
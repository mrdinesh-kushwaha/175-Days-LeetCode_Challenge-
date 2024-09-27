class MyCalendarTwo {
public:
    vector<pair<int,int>>doubleOverLap;
    vector<pair<int,int>> bookings;
    bool checkOverLap(int start1,int end1,int start2,int end2){
        return max(start1,start2) < min(end1,end2);
    }
    pair<int,int>findOverLappedRegion(int start1,int end1,int start2,int end2){
        return {max(start1,start2),min(end1,end2)};
    }
    MyCalendarTwo() {
        
    }    
    bool book(int start, int end) {
        // check double overlapping.......
        for(auto& region: doubleOverLap){
            if(checkOverLap(region.first,region.second,start,end)){
                return false;
            }
        }
        // check creating, double overLapping
        for(auto &booking: bookings){
            if(checkOverLap(booking.first,booking.second,start,end)){
                // now store into double overlapping
                doubleOverLap.push_back(findOverLappedRegion(booking.first,booking.second,start,end));
            }
        }
        bookings.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int>minutes;
        int mini=INT_MAX;

       for(auto time:timePoints){
        int hour=stoi(time.substr(0,2));
        int minute=stoi(time.substr(3,2));
        int totalmin=(hour*60+minute);
        minutes.push_back(totalmin);
       }
       sort(begin(minutes),end(minutes));

        for(int i=1;i<n;i++){
            mini=min(mini,(minutes[i]-minutes[i-1]));
        }
        mini = min(mini, (1440 - minutes.back() + minutes.front())); // maxMinutes 1day=1440min

        return mini;
    }
};
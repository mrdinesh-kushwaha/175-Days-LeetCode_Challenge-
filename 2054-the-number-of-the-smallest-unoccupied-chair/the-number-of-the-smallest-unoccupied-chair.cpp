class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        int n= times.size();
        vector<int>chairs(n,-1);

        int targetfriend= times[targetFriend][0];
        sort(begin(times),end(times));
        for(vector<int>&time: times){
            int arrival= time[0];
            int depart= time[1];

            for(int i=0;i<n;i++){
                if(chairs[i]<=arrival){
                    chairs[i]= depart;
                    
                    if(arrival == targetfriend){
                        return i;
                    }
                    break;
                }
            }
        }
        return -1;
    }
};